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

// Method 1
int findmid(Node *&head)
{

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

// Method 2
/*
 * find length and mid = length/2
 */

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 3);
    insertAttail(tail, 4);
    insertAttail(tail, 5);
    print(head);
    cout << "Middle of list : " << findmid(head) << endl;

    cout << endl;
    insertAttail(tail, 6);
    print(head);
    cout << "Middle of list : " << findmid(head) << endl;

    cout << endl;
    Node *p = new Node(23);
    print(p);
    cout << "Middle of list : " << findmid(p) << endl;

    return 0;
}
