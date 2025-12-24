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
// data replace
void sort(Node *&head)
{
    int countzero = 0;
    int countone = 0;
    int counttwo = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            countzero++;
        else if (temp->data == 1)
            countone++;
        else if (temp->data == 2)
            counttwo++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (countzero > 0)
        {
            temp->data = 0;
            countzero--;
        }
        else if (countone > 0)
        {
            temp->data = 1;
            countone--;
        }
        else if (counttwo > 0)
        {
            temp->data = 2;
            counttwo--;
        }
        temp = temp->next;
    }
}

// Method 2
// Not data replace
void insertnode(Node* &tail,Node* curt)
{
    tail->next=curt;
    tail=curt;
}

void sortlist(Node *&head)
{
    Node *zerolist = new Node(-1);
    Node *zerotail = zerolist;
    Node *onelist = new Node(-1);
    Node *onetail = onelist;
    Node *twolist = new Node(-1);
    Node *twotail = twolist;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertnode(zerotail,temp);
        }
        else if (temp->data == 1)
        {
           insertnode(onetail,temp);
        }
        else if (temp->data == 2)
        {
            insertnode(twotail,temp);
        }
        temp=temp->next;
    }
    zerotail->next = NULL;
    onetail->next = NULL;
    twotail->next = NULL;
    if (zerolist->next != NULL)
    {
        head = zerolist->next;
        if (onelist->next != NULL)
        {
            zerotail->next = onelist->next;
            if (twolist->next != NULL)
            {
                onetail->next = twolist->next;
            }
        }
        else
        {
            if (twolist->next != NULL)
            {
                zerotail->next = twolist->next;
            }
        }
    }
    else
    {
        if (onelist->next!=NULL)
        {
            head=onelist->next;
            if (twolist->next!=NULL)
            {
                onetail->next=twolist->next;
            }
        }
        else 
        {
            if(twolist!=NULL)
               head=twolist->next;
            else
              head=NULL;
        }
        
    }
    delete zerolist;
    delete onelist;
    delete twolist;
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, 0);
    insertAttail(tail, 2);
    insertAttail(tail, 1);
    insertAttail(tail, 2);
    insertAttail(tail, 2);
    insertAttail(tail, 0);
    cout << "Befor Sort ";
    print(head);

    //sort(head);
    sortlist(head);
    cout << "After Sort ";
    print(head);

    return 0;
}