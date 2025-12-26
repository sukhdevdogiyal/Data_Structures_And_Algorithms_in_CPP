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
Node* add(Node* &head1,Node* &head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* ptr1 =head1;
    Node* ptr2 =head2;
    int c = 0;
    int sum = 0;
    Node* tail = NULL;
    while (ptr1!=NULL&&ptr2!=NULL)
    {
        sum = c + ptr1->data+ptr2->data;
        c = sum/10;
        sum = sum%10;
        ptr1->data = sum;
        tail=ptr1;
        //cout<<sum<<" ";
        //if(ptr1->next==NULL) break;
        ptr1= ptr1->next;
        ptr2= ptr2->next;
    }
    while (ptr1!=NULL)
    {
        sum = c + ptr1->data;
        c = sum/10;
        sum = sum%10;
        ptr1->data = sum;
        tail=ptr1;
        //if(ptr1->next==NULL) break;
        ptr1=ptr1->next;
    }
    while (ptr2!=NULL)
    {
        sum = c + ptr2->data;
        c = sum/10;
        sum = sum%10;
        ptr2->data = sum;
        tail->next = ptr2;
        tail=tail->next; 
        ptr2=ptr2->next;
    }
    if (c)
    {
        sum = c;
        Node* newnode = new Node(sum);
        tail->next = newnode;
    }
    head1 = reverse(head1);
    return head1;
    
    
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head1 = node1;
    Node *tail = node1;
    insertAttail(tail, 9);
    // insertAttail(tail, 3);
    // insertAttail(tail, 4);
    // insertAttail(tail, 5);
    // insertAttail(tail, 6);
    cout<<"first ";
    print(head1);
    
    Node *node2 = new Node(9);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAttail(tail2, 9);
    // insertAttail(tail2, 3);
    // insertAttail(tail2, 2);
    // insertAttail(tail2, 3);
    // insertAttail(tail2, 4);
    cout<<"second ";
    print(head2);
    
    Node* head = add(head1,head2);
    cout<<"sum of two ";
    print(head);

    return 0;
}
