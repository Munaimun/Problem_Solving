// Problem Statement:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each node contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
// Example:
// l1 = 2 -> 4 -> 3   (342)
// l2 = 5 -> 6 -> 4   (465)
// Output: 7 -> 0 -> 8   (807)
//
// You must handle digit-by-digit addition and carry.
// Return the head of the new reversed result list.
//
//
// Time Complexity: O(n + m)
// You traverse both lists once.
//
// Space Complexity: O(1) extra space
// You create only the result list (allowed). No extra data structures.

#include <bits/stdc++.h>
using namespace std;

// Basic singly linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node to simplify pointer handling
        ListNode* parent = new ListNode(-1);
        ListNode* pre = parent;

        int carry = 0;

        // Process until both lists are done AND no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            // ✅ CORRECTION:
            // Previous incorrect: (l1->next != nullptr) — this crashes if l1 == nullptr
            int d1 = (l1 != nullptr) ? l1->val : 0;
            int d2 = (l2 != nullptr) ? l2->val : 0;

            // Add digits + carry
            int sum = d1 + d2 + carry;

            // Create new node for the digit
            pre->next = new ListNode(sum % 10);

            // Update carry
            carry = sum / 10;

            // Move pointers forward
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            pre = pre->next;
        }

        // Skip the dummy and return the real head
        return parent->next;
    }
};


// Helper to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> nullptr\n";
}

int main() {
    // Example input
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}