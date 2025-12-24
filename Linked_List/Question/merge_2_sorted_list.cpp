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

void code(Node *&small, Node *&big)
{
    Node *smallprev = small;
    Node *smallcurr = small->next;
    Node *bigcurr = big;
    if (smallcurr == NULL)
    {
        smallprev->next = bigcurr;
    }

    while (smallcurr != NULL && bigcurr != NULL)
    {
        if (smallcurr->data <= bigcurr->data)
        {
            smallprev = smallcurr;
            smallcurr = smallcurr->next;
        }
        else
        {
            smallprev->next = bigcurr;
            bigcurr = bigcurr->next;
            smallprev = smallprev->next;
            smallprev->next = smallcurr;
        }
    }
    if (bigcurr != NULL)
    {
        smallprev->next = bigcurr;
    }
}
Node *merge(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data < head2->data)
    {
        code(head1, head2);
        return head1;
    }
    else
    {
        code(head2, head1);
        return head2;
    }
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail1 = node1;
    insertAttail(tail1, 4);
    insertAttail(tail1, 5);
    // insertAttail(tail1, 1);
    // insertAttail(tail1, 2);
    // insertAttail(tail1, 2);
    // insertAttail(tail1, 0);
    cout << "first ";
    print(head1);

    Node *node2 = new Node(2);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAttail(tail2, 3);
    insertAttail(tail2, 5);
    cout << "second ";
    print(head2);

    Node *head = merge(head1, head2);
    cout << "Merge ";
    print(head);

    return 0;
}