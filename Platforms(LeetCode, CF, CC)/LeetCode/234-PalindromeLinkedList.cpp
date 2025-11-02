// Problem Statement:
// Check if a singly linked list is a palindrome.
// A linked list is a palindrome if it reads the same forwards and backwards.
//
// Example:
// Input: 1 -> 2 -> 2 -> 1
// Output: true
//
// Input: 1 -> 2
// Output: false

// Complexity:
// Time: O(n) → one pass to find middle + one pass to reverse + one pass to compare
// Space: O(1) → in-place reversal, no extra space

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    // Helper function to reverse a linked list
    ListNode* Reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while(head) {
            ListNode* next = head->next; // store next node
            head->next = pre;            // reverse current node's pointer
            pre = head;                  // move 'pre' to current node
            head = next;                 // move to next node
        }
        return pre; // new head of reversed list
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true; // empty or single-node list is palindrome

        // Step 1: Find the middle using slow & fast pointers
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next; // move fast by 2
            slow = slow->next;       // move slow by 1
        }
        // 'slow' is now at the start of the second half(mid)

        // Step 2: Reverse the second half
        ListNode* second = Reverse(slow);

        // Step 3: Compare first half and reversed second half
        ListNode* first = head;
        while(second) { // iterate till the end of second half
            if(first->val != second->val) return false; // mismatch -> not palindrome
            first = first->next;
            second = second->next;
        }

        return true; // all matched -> palindrome
    }
};

// Optional helper to test
ListNode* createList(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(int i=1;i<vals.size();i++){
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<" -> ";
        head = head->next;
    }
    cout<<" -> nullptr\n";
}

int main(){
    ListNode* head = createList({1,2,2,1});
    Solution sol;
    cout<<"Is Palindrome? "<<(sol.isPalindrome(head) ? "Yes" : "No")<<"\n";
    return 0;
}
