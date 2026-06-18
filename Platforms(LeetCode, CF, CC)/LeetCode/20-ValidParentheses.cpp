/*
=========================================
Problem: Valid Parentheses

Given a string `s` containing just the characters
'(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
1. Every opening bracket has a corresponding closing bracket.
2. Brackets are closed in the correct order.
3. Every closing bracket matches the most recent unmatched opening bracket.

Example:
Input:  s = "()[]{}"
Output: true

Input:  s = "(]"
Output: false

-----------------------------------------
Approach:
- Use a stack to keep track of opening brackets.
- Traverse the string:
    * If the current character is an opening bracket,
      push it onto the stack.
    * If it's a closing bracket:
        - If the stack is empty, return false.
        - Check whether the top of the stack
          matches the current closing bracket.
        - If it matches, pop the stack.
        - Otherwise, return false.
- At the end, if the stack is empty,
  all brackets were matched correctly.

Time Complexity: O(n)
Space Complexity: O(n)
=========================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Stack to store opening brackets
        stack<char> openings;

        // Traverse each character in the string
        for (int i = 0; i < s.size(); i++) {

            // If it's an opening bracket, push it
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                openings.push(s[i]);
            }
            else { // Current character is a closing bracket

                // No opening bracket available to match
                if (openings.size() == 0)
                    return false;

                // Check if the current closing bracket
                // matches the top opening bracket
                if ((openings.top() == '(' && s[i] == ')') ||
                    (openings.top() == '{' && s[i] == '}') ||
                    (openings.top() == '[' && s[i] == ']')) {

                    // Found a valid pair, remove the opening bracket
                    openings.pop();
                }
                else {
                    // Mismatched bracket pair
                    return false;
                }
            }
        }

        // If stack is empty, all brackets were matched
        return openings.size() == 0;
    }
};