#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Create linked list from array
ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < n; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Print linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Remove Nth node from end
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *ptr = head;

    // Step 1: Count total nodes
    while (ptr != nullptr)
    {
        len++;
        ptr = ptr->next;
    }

    // Step 2: If removing the head
    if (len == n)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Step 3: Move to (len - n)th node
    ptr = head;
    for (int i = 1; i < len - n; i++)
        ptr = ptr->next;

    // Step 4: Remove nth from end
    ListNode *temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;

    return head;
}

// Main function
int main()
{
    //int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list from array
    ListNode *head = createLinkedList(arr, n);

    cout << "Original List: ";
    printList(head);

    int k = 1; // remove 2nd node from end
    head = removeNthFromEnd(head, k);

    cout << "After Removing " << k << "th Node from End: ";
    printList(head);

    return 0;
}
