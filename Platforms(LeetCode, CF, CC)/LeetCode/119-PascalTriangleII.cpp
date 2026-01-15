// Problem Statement:
// Given an integer rowIndex, return the rowIndex-th (0-indexed) row
// of Pascal's Triangle.
//
// In Pascal's Triangle:
// - The first and last elements of each row are always 1
// - Each inner element is the sum of the two elements directly above it
//
// Example:
// Input: rowIndex = 4
// Output: [1, 4, 6, 4, 1]

// Time Complexity:
// O(rowIndex^2)
// For each row i, we update i elements in the array.

// Space Complexity:
// O(rowIndex)
// We store only one row instead of the full triangle.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;

        // Base case: first row of Pascal's Triangle
        row.push_back(1);

        // Build each row up to rowIndex
        for (int i = 1; i <= rowIndex; i++) {

            // Add 1 at the end of the row
            row.push_back(1);

            // Update the row from right to left
            // This prevents overwriting values that are still needed
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j - 1] + row[j];
            }
        }

        return row;
    }
};
