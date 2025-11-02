//Problem Statement:
// Merge two sorted singly linked lists and return it as a new sorted list.
// The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
// Input: l1 = 1->2->4, l2 = 1->3->4
// Output: 1->1->2->3->4->4
//
//The merge must maintain sorted order.

//Complexity:
// Time: O(n + m) → traverse both lists once
// Space: O(1) → in-place merge, only dummy node extra

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
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
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // Dummy node to simplify pointer manipulation
        ListNode *parent = new ListNode(-1);
        ListNode *pre = parent;

        // Traverse both lists until one is exhausted
        while (l1 != nullptr && l2 != nullptr)
        {
            // Compare the current nodes of l1 and l2
            if (l1->val <= l2->val)
            {
                // Case 1: l1's value is smaller or equal
                // Attach l1's current node to the merged list
                pre->next = l1;

                // Move l1 forward to its next node
                l1 = l1->next;
            }
            else
            {
                // Case 2: l2's value is smaller
                // Attach l2's current node to the merged list
                pre->next = l2;

                // Move l2 forward to its next node
                l2 = l2->next;
            }

            // Move the 'pre' pointer forward to point to the last node
            // of the merged list (just attached), so we can attach the next node in the next iteration
            pre = pre->next;
        }

        // Attach remaining nodes (if any) from non-empty list
        if (l1 != nullptr)
            pre->next = l1;
        else
            pre->next = l2;

        // Return head of merged list (skip dummy node)
        return parent->next;
    }
};

// Helper to create a linked list from vector
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;   // If input vector is empty, return null (no nodes)

    // Create the head node with the first value
    ListNode *head = new ListNode(vals[0]);

    // 'curr' will point to the last node in the list as we build it
    ListNode *curr = head;

    // Loop through the remaining values in the vector
    for (int i = 1; i < vals.size(); i++)
    {
        // Create a new node for each value and attach it to the 'next' of the last node
        curr->next = new ListNode(vals[i]);

        // Move 'curr' forward to the newly created node
        curr = curr->next;
    }

    // Return the head of the linked list
    return head;
}


// Helper to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << " -> nullptr\n";
}

int main()
{
    ListNode *l1 = createList({1, 2, 4});
    ListNode *l2 = createList({1, 3, 4});

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode *merged = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

