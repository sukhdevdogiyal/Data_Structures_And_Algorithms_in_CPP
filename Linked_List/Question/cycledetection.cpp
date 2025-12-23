/*
 * two method
 * 1. using map
 *    T. C. = O(n)
 *    S. C. = O(n)
 * 2. floyd's cycle detection algo
 *    T. C. = O(n)
 *    S. C. = O(1)
 */
#include <iostream>
#include <map>
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

// method 1
// using map
// s. c. = o(n)
bool loopdetection(Node *head)
{
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "loop head : " << temp->data << endl;
            return true;
        }
        else
        {
            visited[temp] = true;
            temp = temp->next;
        }
    }
    return false;
}
void usingmap(Node *&head)
{
    if (loopdetection(head))
    {
        cout << "loop is present" << endl;
    }
    else
    {
        cout << "loop is not present" << endl;
    }
}

// Method 2
// Floyd's cycle detection algo
bool cycledetection(Node *&head)
{

    if (head == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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
int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    Node *tail = head;
    print(head);
    usingmap(head);
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
    usingmap(head);
    usingfloydalgo(head);

    cout << endl;
    tail->next = NULL;
    print(head);
    usingmap(head);
    usingfloydalgo(head);

    cout << endl;
    Node *newnode = new Node(5);
    newnode->next = newnode;
    print(newnode);
    usingmap(newnode);
    usingfloydalgo(newnode);

    cout << endl;
    // my list is : 1 2 3 4 5 6 7 3
    tail->next = ptr1;
    // print(head);
    cout << "list : 1 2 3 4 5 6 7 3" << endl;
    usingmap(head);
    usingfloydalgo(head);

    return 0;
}
