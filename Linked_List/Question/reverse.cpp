#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertAttail(Node* &tail,int data)
{
    Node* newnode = new Node(data);
    tail->next=newnode;
    tail = newnode;
}
void print(Node* &head)
{
    Node* temp = head;
    cout<<"List : ";
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
    
}

// method 1
void reverse(Node* &head,Node* &tail)
{
    tail=head;
    Node* pre = NULL;
    Node* ptr = head;
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        head->next = pre;
        pre=head;
        head=ptr;
    }
    head=pre;
    
}
 
// method 2
int main(int argc, char const *argv[])
{
    Node* node1 =new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,4);
    insertAttail(tail,5);
    cout<<"Befor Reverse ";
    print(head);
    cout<<"After Reverse ";
    reverse(head,tail);
    print(head);
    return 0;
}
