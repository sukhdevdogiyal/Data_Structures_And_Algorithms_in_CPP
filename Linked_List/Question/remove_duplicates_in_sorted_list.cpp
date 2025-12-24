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

void removeduplicate(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *ptr = head;
    Node *next = head->next;
    Node *deletenode = NULL;
    while (next != NULL)
    {
        if (ptr->data == next->data)
        {
            ptr->next = next->next;
            deletenode = next;
            next = next->next;
            delete (deletenode);
        }
        else
        {
            ptr = next;
            next = next->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail,2);
    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,3);
    insertAttail(tail,3);
    insertAttail(tail,4);
    cout << "Befor Remove Duplicate ";
    print(head);

    removeduplicate(head);
    cout << "After Remove Duplicate ";
    print(head);

    return 0;
}
