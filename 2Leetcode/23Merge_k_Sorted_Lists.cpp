// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
vector<Node *> buildLL(vector<vector<int>> arr)
{
    vector<Node *> lists;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *head = NULL;
        Node *tail = NULL;
        for (int j = 0; j < arr[i].size(); j++)
        {
            Node *temp = new Node(arr[i][j]);
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        lists.push_back(head);
    }
    return lists;
}
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
// T.C = O(n*klog(k))
// S.C = O(n*k)
Node *mergeKLists(vector<Node *> &lists)
{
    // use minheap store all list smallest element
    priority_queue<Node *, vector<Node *>, compare> pq;
    // store all list first element
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
            pq.push(lists[i]);
    }
    if (pq.empty())
        return NULL;
    // merge all lists
    // top of pq put into ans and same row new data add into pq
    Node *head = NULL;
    Node *tail = NULL;
    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        if (temp->next)
        {
            pq.push(temp->next);
        }
    }
    tail->next = NULL;
    return head;
}
void print(Node *head)
{
    cout << "Merge k sorted List : ";
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{1, 3, 5, 7},
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};
    vector<Node *> lists = buildLL(mat);
    Node *head = mergeKLists(lists);
    print(head);
    cout << endl;

    mat = {{1, 2, 3, 4},
           {2, 2, 3, 4},
           {5, 5, 6, 6},
           {7, 8, 9, 9}};
    lists = buildLL(mat);
    head = mergeKLists(lists);
    print(head);
    cout << endl;

    mat = {{1, 4, 5},
           {1, 3, 4},
           {2, 6}};
    lists = buildLL(mat);
    head = mergeKLists(lists);
    print(head);
    cout << endl;

    mat = {{}};
    lists = buildLL(mat);
    head = mergeKLists(lists);
    print(head);
    cout << endl;

    mat = {};
    lists = buildLL(mat);
    head = mergeKLists(lists);
    print(head);
    cout << endl;

    return 0;
}
