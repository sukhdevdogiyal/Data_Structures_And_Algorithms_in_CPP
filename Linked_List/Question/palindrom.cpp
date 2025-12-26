#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAttail(Node *&tail, int data)
{
    Node *newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}
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

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *forward = NULL;
    while (cur != NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}
bool check(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // find mid
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse 2 half
    Node *head2 = reverse(slow->next);
    slow->next = head2;
    Node *ptr1 = head;
    Node *ptr2 = head2;
    while (ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            return false;
        }
        else
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return true;
}
void palindrom(Node *&head)
{
    if (check(head))
    {
        cout << "list is palindrom" << endl;
    }
    else
    {
        cout << "list is not palindrom" << endl;
    }
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 3);
    insertAttail(tail, 2);
    insertAttail(tail, 1);

    print(head);
    palindrom(head);
    print(head);

    return 0;
}
