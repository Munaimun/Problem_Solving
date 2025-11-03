// Problem Statement:
// -------------------
// Given the head of a singly linked list, sort the list in ascending order and return its head.
// You must use O(n log n) time complexity and constant auxiliary space (i.e., O(1) extra space apart from recursion).

// Approach:
// ----------
// We use the Merge Sort algorithm on linked lists, which works efficiently with O(n log n) complexity.
// The algorithm involves three main steps:
// 1. **Find the middle node** to split the list into two halves using the slow & fast pointer approach.
// 2. **Recursively sort** each half.
// 3. **Merge** the two sorted halves into a single sorted list.

// Time Complexity:  O(n log n)
// Space Complexity: O(log n)   (due to recursion stack)

// ------------------------------------------------------------

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
    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* parent = new ListNode(-1);  // Dummy node to simplify logic
        ListNode* cur = parent;

        // Compare nodes and attach the smaller one to the result
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        // Attach remaining nodes (if any)
        if (l1) cur->next = l1;
        else if (l2) cur->next = l2;

        return parent->next; // Return head of merged list
    }

    // Find the middle of the linked list
    ListNode *getMid(ListNode *head) {
        ListNode *fast = head, *slow = head;

        // Move fast by 2 steps and slow by 1 step
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow; // 'slow' points to mid node
    }

    // Recursive merge sort function
    ListNode *mergeSort(ListNode *head) {
        // Base case: single element or empty list
        if (!head || !head->next)
            return head;

        // Step 1: Split the list into two halves
        ListNode *mid = getMid(head);
        ListNode *next = mid->next;
        mid->next = nullptr; // Break the list into two parts

        // Step 2: Recursively sort both halves
        ListNode *l1 = mergeSort(head);
        ListNode *l2 = mergeSort(next);

        // Step 3: Merge the two sorted halves
        return merge(l1, l2);
    }

public:
    // Main function to sort the list
    ListNode *sortList(ListNode *head) {
        if (head == nullptr)
            return head;
        return mergeSort(head);
    }
};

// Example demonstration
int main() {
    // Example: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode* sorted = s.sortList(head);

    cout << "Sorted List: ";
    while (sorted) {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }
    cout << endl;

    return 0;
}