// Problem Statement:
// Given the head of a singly linked list, reverse the list and return the new head.
//
// Example:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
// Output: 5 -> 4 -> 3 -> 2 -> 1 -> nullptr
//
// Goal: Reverse the pointers of each node so that the list is reversed in-place.
//
// Time Complexity: O(n)
// Because we traverse each node exactly once.
//
// Space Complexity: O(1)
// Because we reverse the list in-place without using extra data structures.

#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 'pre' will point to the previous node (initially null)
        ListNode* pre = nullptr;

        // 'cur' will traverse the list
        ListNode* cur = head;

        // 'next' temporarily holds the next node before we reverse the pointer
        ListNode* next = nullptr;

        // Traverse the list until all nodes are reversed
        while (cur != nullptr) {
            next = cur->next;     // Save the next node
            cur->next = pre;      // Reverse the link
            pre = cur;            // Move 'pre' one step forward
            cur = next;           // Move 'cur' to the next node
        }

        // 'pre' is now the new head of the reversed list
        return pre;
    }
};

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> nullptr" << endl;
}

int main() {
    // Example input
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    // Reverse the list
    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    cout << "Reversed list: ";
    printList(reversed);

    return 0;
}