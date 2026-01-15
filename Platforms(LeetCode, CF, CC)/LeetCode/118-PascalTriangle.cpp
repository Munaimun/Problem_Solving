// Problem Statement:
// Given an integer numRows, generate the first numRows of Pascal's Triangle.
// In Pascal's Triangle, each number is the sum of the two numbers directly above it.
//
// Example:
// Input: numRows = 5
// Output:
// [
//   [1],
//   [1,1],
//   [1,2,1],
//   [1,3,3,1],
//   [1,4,6,4,1]
// ]

// Time Complexity:
// O(numRows^2)
// Because for each row i, we calculate i elements.

// Space Complexity:
// O(numRows^2)
// Because we store the entire Pascal's Triangle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri;
        pascalTri.push_back({1}); // first row with just 1

        for (int i = 1; i < numRows; i++) {
            vector<int> newTri; // for every row
            newTri.push_back(1); // always add 1 in the beginning
            for (int j = 1; j < pascalTri.back().size(); j++)
                newTri.push_back(pascalTri.back()[j] + pascalTri.back()[j - 1]);   // Each middle element is the sum of two elements above it from the previous row
            newTri.push_back(1); // always add 1 in the end
            pascalTri.push_back(newTri); // add this row in the pascal's triangle
        }

        return pascalTri;
    }
};