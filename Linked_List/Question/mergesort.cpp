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

// findmid
Node* findmid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}
// merge
Node* merge(Node* left,Node* right)
{
    if(left==NULL) return right;
    if(right==NULL) return left;
    Node* ans = new Node(-1);
    Node* temp =ans;
    while (left!=NULL&&right!=NULL)
    {
        if (left->data<right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while (left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while (right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    Node* result =ans->next;
    delete(ans);
    return result;
    
}
Node* mergesort(Node* head)
{
    if(head==NULL||head->next==NULL) 
    return head;

    // find mid
    Node* mid = findmid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next=NULL;

    // recursion call
    left = mergesort(left);
    right = mergesort(right);

    // merge
    Node* result = merge(left,right);
    return result;
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 2);
    insertAttail(tail, 1);
    insertAttail(tail, 5);
    insertAttail(tail, 9);
    insertAttail(tail, 1);

    print(head);
    Node* head1 = mergesort(head);
    print(head1);

    return 0;
}
