// Problem: Delete a node in a singly linked list when only given access to that node
// You cannot access the head of the list, only the node to be deleted

// Time Complexity: O(1) — all operations are done in constant time
// Space Complexity: O(1) — no extra space used

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

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;

        // Skip the next node by linking current node to the node after next
        ListNode* temp = node->next;
        node->next = node->next->next;

        // Optional: free memory of the removed node
        delete temp;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution sol;
    sol.deleteNode(head->next); // delete node with value 5

    // Print list to verify
    ListNode* curr = head;
    while(curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    // Output: 4 1 9

    return 0;
}
