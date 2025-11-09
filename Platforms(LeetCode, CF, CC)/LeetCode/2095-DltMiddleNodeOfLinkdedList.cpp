// Problem: Delete the middle node of a singly linked list
// Given the head of a linked list, remove its middle node and return the head of the modified list.
// If the list has only one node, return nullptr.

// Time Complexity: O(N) — we traverse the list once to find the middle
// Space Complexity: O(1) — no extra space is used, just pointers

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
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        // Edge case: if list has 0 or 1 node, removing middle results in empty list
        if (!head || !head->next)
            return nullptr;

        // Initialize pointers for fast/slow technique
        ListNode *slow = head;  // will point to the middle node
        ListNode *fast = head;  // will move twice as fast
        ListNode *pre = nullptr; // keeps track of node before slow

        // Move fast pointer two steps and slow pointer one step each time
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }

        // At this point, slow points to middle node
        // pre points to node just before middle
        // Remove middle node
        pre->next = slow->next;
        delete slow;

        return head; // return updated list head
    }
};

// Helper function to print linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create linked list from input [1,3,4,7,1,2,6]
    vector<int> vals = {1, 3, 4, 7, 1, 2, 6};
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }

    Solution sol;
    head = sol.deleteMiddle(head);

    printList(head);

    return 0;
}
