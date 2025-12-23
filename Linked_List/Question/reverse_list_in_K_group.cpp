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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAttail(Node *&tail, int data)
{
    Node *newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void reversekgroup(Node *&head, int k)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int count = 0;
    Node *prevtail = head;
    // Node* curhead=head;
    Node *curtail = head;
    while (cur != NULL)
    {
        count++;
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
        if (count % k == 0 || cur == NULL)
        {
            if (count <= k)
            {
                head = prev;
            }
            else
            {
                prevtail->next = prev;
                prevtail = curtail;
            }
            curtail = cur;
            // prehead=curhead;
            // curhead=cur;
            prev = NULL;
        }
    }
}
Node *kreverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
       // return NULL;
    }
    Node *cur = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int count = 0;
    while (count < k && cur != NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
        count++;
    }
    if (count < k)
    {
        cur = prev;
        prev = NULL;
        forward = NULL;
        while (count >0  && cur != NULL)
        {
            forward = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forward;
            count--;
        }
        return prev;
    }

    if (forward != NULL)
    {
        head->next = kreverse(forward, k);
    }

    return prev;
}
int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    Node *tail = head;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);
    insertAttail(tail, 5);
    insertAttail(tail, 6);
    // insertAttail(tail,7);
    // insertAttail(tail,8);
    // insertAttail(tail,9);
    // insertAttail(tail,10);
    cout << "Befor Reverse ";
    print(head);
    int k = 4;
    // reversekgroup(head,k);
    cout << "After Reverse ";
    print(head);
    Node *newhead = kreverse(head, k);
    print(newhead);
    return 0;
}
