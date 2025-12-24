#include <iostream>
#include <map>
#include <unordered_set>
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
// T.C = O(n^2)
// S.C. = O(1)
void removeduplicate(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *curt = head;
    Node *prev = head;
    Node *next = head->next;
    Node *deletenode = NULL;
    while (curt != NULL)
    {
        prev = curt;
        next = curt->next;
        while (next != NULL)
        {
            if (curt->data == next->data)
            {
                deletenode = next;
                prev->next = next->next;
                next = next->next;
                delete (deletenode);
            }
            else
            {
                prev = next;
                next = next->next;
            }
        }
        curt = curt->next;
    }
}

// method 2
// using map
// T.C. = O(nlog(n))
// S.C. = O(n)
void removeduplicateusingmap(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    map<int, bool> visited;
    Node *curt = head;
    Node *prev = NULL;
    Node *deletenode = NULL;
    while (curt != NULL)
    {
        if (visited[curt->data] == true)
        {
            deletenode = curt;
            prev->next = curt->next;
            curt = curt->next;
            delete (deletenode);
        }
        else
        {
            visited[curt->data] = true;
            prev = curt;
            curt = curt->next;
        }
    }
}

// method
// using unordered_set;
// T.C. = O(n)
// S.C. = O(n)
void removeduplicateusingunordered_set(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    unordered_set<int> visited;
    Node *curt = head;
    Node *prev = NULL;
    Node *deletenode = NULL;
    while (curt != NULL)
    {
        if (visited.count(curt->data))
        {
            deletenode = curt;
            prev->next = curt->next;
            curt = curt->next;
            delete (deletenode);
        }
        else
        {
            visited.insert(curt->data);
            prev = curt;
            curt = curt->next;
        }
    }
}
int main(int argc, char const *argv[])
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;
    insertAttail(tail, -1);
    insertAttail(tail, 5);
    insertAttail(tail, 4);
    insertAttail(tail, 2);
    insertAttail(tail, 2);
    insertAttail(tail, 1);
    cout << "Befor Remove Duplicate ";
    print(head);

    // removeduplicate(head);
    // removeduplicateusingmap(head);
    removeduplicateusingunordered_set(head);
    cout << "After Remove Duplicate ";
    print(head);

    return 0;
}