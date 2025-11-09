// Problem: Remove all elements from a linked list with a given value
// Given the head of a linked list and an integer val, remove all nodes where node->val == val
// Return the new head of the linked list

// Time Complexity: O(N) — we traverse the list once
// Space Complexity: O(1) — only constant extra space for pointers

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
    ListNode* removeElements(ListNode* head, int val)
    {
        // Create a dummy node to simplify edge cases (like removing the head)
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* ptr = dummy;

        // Traverse the list
        while(ptr->next)
        {
            if(ptr->next->val == val)
            {
                // Node needs to be removed
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next; // remove the node
                delete temp; // free memory
            }
            else
            {
                // Move forward only if node is not removed
                ptr = ptr->next;
            }
        }

        return dummy->next; // new head
    }
};

//helper function to print the linked list
void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    vector<int> vals = {1,2,6,3,4,5,6};
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(int i=1;i<vals.size();i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }

    Solution sol;
    head = sol.removeElements(head, 6); // remove all 6s

    printList(head); // Expected output: 1 2 3 4 5

    return 0;
}
