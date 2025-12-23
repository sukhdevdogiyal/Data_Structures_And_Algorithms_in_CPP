/*
 * floyd's cycle detection algo
 *    T. C. = O(n)
 *    S. C. = O(1)
 */
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    cout << "List : ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head && temp != NULL);
    if (temp != NULL)
    {
        cout << temp->data;
    }

    cout << endl;
}

void insertAttail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
    newnode->next = head;
}

// Floyd's cycle detection algo
Node *cycledetection(Node *&head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
void usingfloydalgo(Node *&head)
{
    if (cycledetection(head))
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "loop is not present" << endl;
    }
}

// loop start node
Node *startnode(Node *&head)
{
    Node *fast = cycledetection(head);
    if (fast == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
void getstartnode(Node *&head)
{
    if (startnode(head))
    {
        cout << "start node : " << startnode(head)->data << endl;
    }
}

// Remove loop
void removeloop(Node *&head)
{
    if (head == NULL)
        return;
    Node *start = startnode(head);
    if (!start)
        return;
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    Node *tail = head;
    print(head);
    usingfloydalgo(head);

    cout << endl;
    insertAttail(head, tail, 2);
    insertAttail(head, tail, 3);
    Node *ptr1 = tail;
    insertAttail(head, tail, 4);
    insertAttail(head, tail, 5);
    insertAttail(head, tail, 6);
    insertAttail(head, tail, 7);

    print(head);
    usingfloydalgo(head);
    getstartnode(head);
    usingfloydalgo(head);

    cout << endl;
    tail->next = NULL;
    print(head);
    usingfloydalgo(head);
    getstartnode(head);

    cout << endl;
    Node *newnode = new Node(5);
    newnode->next = newnode;
    print(newnode);
    usingfloydalgo(newnode);
    getstartnode(newnode);
    removeloop(newnode);
    print(newnode);

    cout << endl;
    // my list is : 1 2 3 4 5 6 7 3
    tail->next = ptr1;
    // print(head);
    cout << "list : 1 2 3 4 5 6 7 3" << endl;
    usingfloydalgo(head);
    getstartnode(head);
    removeloop(head);
    print(head);
    return 0;
}
