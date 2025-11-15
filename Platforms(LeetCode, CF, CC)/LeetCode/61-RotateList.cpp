// Problem: Given a singly linked list, rotate the list to the right by k places.
// Example: head = [1,2,3,4,5], k = 2 → output: [4,5,1,2,3]

/*
Time Complexity: O(n)
- Count length: O(n)
- Find split point: O(n)
- Reconnect nodes: O(1)
Total: O(n)

Space Complexity: O(1)
- In-place rotation, no extra memory used
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
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Edge cases: empty or single-node list
        if (!head || !head->next)
            return head;

        int len = 1;
        ListNode *dummy = head;

        // counting the length of the LinkedList
        while (dummy->next)
        {
            dummy = dummy->next;
            len++;
        }

        // compute effective rotations
        int pos = k % len;
        if (pos == 0)
            return head; // no rotation needed

        ListNode *cur = head;
        // find the node just before the new head
        for (int i = 0; i < len - pos - 1; i++)
            cur = cur->next;

        // rotate
        ListNode *newHead = cur->next; // new head after rotation
        cur->next = nullptr;           // break the list
        dummy->next = head;            // connect old tail to old head

        return newHead;
    }
};