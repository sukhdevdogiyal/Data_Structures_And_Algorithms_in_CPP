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
    if (temp!=NULL)
    {
        cout<<temp->data;
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
bool cheak(Node *&head, Node *ptr)
{
    if (ptr == head)
    {
        return 1;
    }
    if (ptr == NULL)
    {
        return 0;
    }
    cheak(head, ptr->next);
}

// method 2
bool loopdetection(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    if (head->next == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    Node *tail = head;
    print(head);
    // cout << "isCircular = " << cheak(head, head->next) << endl;
    cout << "isCircular = " << loopdetection(head) << endl;

    cout<<endl;
    insertAttail(head, tail, 2);
    insertAttail(head, tail, 3);
    Node *ptr1 = tail;
    insertAttail(head, tail, 4);
    insertAttail(head, tail, 5);
    insertAttail(head, tail, 6);
    insertAttail(head, tail, 7);

    print(head);
    // cout << "isCircular = " << cheak(head, head->next)<<endl;
    cout << "isCircular = " << loopdetection(head) << endl;
    
    
    cout<<endl;
    tail->next=NULL;
    print(head);
    cout << "isCircular = " << loopdetection(head) << endl;


    cout << endl;
    Node *newnode = new Node(5);
    newnode->next = newnode;
    print(newnode);
    cout << "isCircular = " << loopdetection(newnode) << endl;

    cout << endl;
    // my list is : 1 2 3 4 5 6 7 3
    tail->next = ptr1;
    // print(head);
    cout << "list : 1 2 3 4 5 6 7 3" << endl;
    cout << "isCircular = " << loopdetection(head) << endl;

    return 0;
}
