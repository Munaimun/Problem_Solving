// Problem: Reorder a singly linked list in-place so that the list:
// L0 → L1 → … → Ln-1 → Ln
// becomes:
// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// without creating new nodes, only by rearranging the pointers.

/*
Time Complexity: O(n)
- Finding mid: O(n)
- Reversing second half: O(n)
- Merging two halves: O(n)
Total: O(n)

Space Complexity: O(1)
- In-place, no extra nodes or arrays are used
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    // Function to find the middle of the linked list
    ListNode *mid(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; // slow is now at the middle
    }

    // Function to reverse a linked list and return new head
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        return prev; // new head of reversed list
    }

public:
    // Function to reorder the linked list
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // 1. Find middle node
        ListNode *midNode = mid(head);

        // 2. Split list into two halves
        ListNode *secHalf = midNode->next;
        midNode->next = nullptr;

        // 3. Reverse the second half
        secHalf = reverse(secHalf);

        // 4. Merge the two halves alternately
        ListNode *firstHalf = head;
        while (secHalf)
        {
            ListNode *t1 = firstHalf->next;
            ListNode *t2 = secHalf->next;

            firstHalf->next = secHalf;
            secHalf->next = t1;

            firstHalf = t1;
            secHalf = t2;
        }
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
ListNode *createList(vector<int> &vals)
{
    ListNode *head = nullptr, *tail = nullptr;
    for (int val : vals)
    {
        if (!head)
        {
            head = new ListNode(val);
            tail = head;
        }
        else
        {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    // Example input: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode *head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}