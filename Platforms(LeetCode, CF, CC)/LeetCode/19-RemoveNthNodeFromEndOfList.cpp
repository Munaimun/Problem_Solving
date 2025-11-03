#include <bits/stdc++.h>
using namespace std;

/*
🧩 Problem Statement:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:
Input:  head = [1, 2, 3, 4, 5], n = 2
Output: [1, 2, 3, 5]

We must remove the 2nd node from the end (value = 4).

-----------------------------------
Approach (Two-Pointer Technique):
1. Create a dummy node (`parent`) pointing to the head.
   - This handles edge cases (like removing the first node).

2. Move the `fast` pointer `n` steps ahead.

3. Move both `fast` and `slow` pointers one step at a time until `fast` reaches the end.
   - `slow` will now be right before the node that should be removed.

4. Skip the target node by updating `slow->next`.

-----------------------------------
Time Complexity:  O(N)
   (We traverse the list once, where N = number of nodes)

Space Complexity: O(1)
   (We only use constant extra space)
*/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to simplify edge cases (like removing the first node)
        ListNode *parent = new ListNode(-1);
        parent->next = head;

        // Two pointers, both start from the dummy node
        ListNode *fast = parent, *slow = parent;

        // Move 'fast' n steps ahead
        while (n--)
            fast = fast->next;

        // Move both until 'fast' reaches the end
        // by this 'slow' will be at right before the node to remove
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // remove the node
        slow->next = slow->next->next;

        // Return the new head (skip dummy node)
        return parent->next;
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

int main()
{
    // Example: [1, 2, 3, 4, 5], n = 2
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    int n = 2;
    ListNode *newHead = sol.removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node from End: ";
    printList(newHead);

    return 0;
}
