#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
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
void printrand(Node *&head)
{
    Node *temp = head;
    cout << "Rand data : ";
    while (temp != NULL)
    {
        if(temp->random!=NULL)
        cout << temp->random->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
Node *clone(Node *&head)
{
    Node *temp = head;
    Node *head1 = NULL;
    Node *tail = NULL;

    unordered_map<Node *, Node *> link;

    while (temp != NULL)
    {
        insert(head1, tail, temp->data);
        link[temp] = tail;
        temp = temp->next;
    }
    temp = head;
    Node *ptr = head1;
    while (temp != NULL)
    {
        ptr->random = link[temp->random];
        temp = temp->next;
        ptr = ptr->next;
    }

    return head1;
}

// Method 2
// T.C. = O(n)
// S.C = O(1)
Node *clone2(Node *&oldhead)
{
    Node *temp = oldhead;
    Node *clonehead = NULL;
    Node *clonetail = NULL;

    while (temp != NULL)
    {
        insert(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // link old and clone
    Node *oldcur = oldhead;
    Node *oldnext = oldhead->next;
    Node *clonecur = clonehead;
    Node *clonenext = clonehead->next;
    while (oldcur != NULL)
    {
        oldcur->next = clonecur;
        clonecur->next = oldnext;
        oldcur = oldnext;
        clonecur = clonenext;
        if (oldcur != NULL)
        {
            oldnext = oldnext->next;
            clonenext = clonenext->next;
        }
    }
    // copy rand
    oldcur = oldhead;
    clonecur = oldhead->next;
    while (oldcur!=NULL)
    {
        if(oldcur->random!=NULL)
        clonecur->random = oldcur->random->next;
        oldcur=oldcur->next->next;
        if(oldcur!=NULL)
        clonecur=clonecur->next->next;
    }
    // remove link
    oldcur = oldhead;
    oldnext = oldhead->next->next;
    clonecur = clonehead;
    if(oldnext!=NULL)
    clonenext = clonehead->next->next;
    else clonenext=NULL;
    while (oldcur->next!=NULL&&clonecur->next!=NULL)
    {
        oldcur->next = oldnext;
        clonecur->next = clonenext;
        oldcur=oldnext;
        clonecur=clonenext;
        oldnext = oldnext->next->next;
        if(oldnext!=NULL)
         clonenext = clonenext->next->next;
        else
         break;
    }
    oldcur->next=NULL;
    clonecur->next=NULL;
    return clonehead;

    
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 3);
    Node *node2 = tail;
    insertAttail(tail, 5);
    Node *node3 = tail;
    insertAttail(tail, 9);
    Node *node4 = tail;
    // insertAttail(tail, 5);
    // Node *node5 = tail;

    node1->random = node3;
    node2->random = node3;
    node3->random = NULL;
    node4->random = node3;
   // node5->random = node2;
    print(head);
    printrand(head);

    cout << "clone list " << endl;
    //Node *head1 = clone(head);
    Node *head2 = clone2(head);
    print(head2);
    printrand(head2);

    return 0;
}
