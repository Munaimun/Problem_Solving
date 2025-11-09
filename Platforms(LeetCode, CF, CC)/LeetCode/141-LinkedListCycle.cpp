// Problem: Detect if a linked list has a cycle
// Given the head of a linked list, return true if there is a cycle, else false

// Time Complexity: O(N) — each node is visited at most twice
// Space Complexity: O(1) — only two pointers used

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

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(fast && fast->next){
            fast = fast->next->next;  // move fast 2 steps
            slow = slow->next;        // move slow 1 step

            if(fast == slow)           // pointers meet → cycle detected
                return true;
        }

        return false; // no cycle
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // create cycle

    Solution sol;
    cout << (sol.hasCycle(head) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
