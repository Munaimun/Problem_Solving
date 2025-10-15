/**
 * MERGE SORT IMPLEMENTATION
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     *Combines two sorted subarrays into one sorted subarray
     */
    void merge(vector<int> &arr, int st, int mid, int end)
    {
        vector<int> temp; // Temporary array to store merged result
        int i = st;       // Pointer for left subarray (starts at st)
        int j = mid + 1;  // Pointer for right subarray (starts at mid+1)

        // PHASE 1: Compare and merge elements from both subarrays
        // Continue until one subarray is completely processed
        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])  // <= ensures stability (equal elements maintain order)
            {
                temp.push_back(arr[i]); // Take from left subarray
                i++;                    // Move left pointer forward
            }
            else
            {
                temp.push_back(arr[j]); // Take from right subarray
                j++;                    // Move right pointer forward
            }
        }

        // PHASE 2: Copy remaining elements from left subarray (if any)
        // This runs when right subarray is exhausted but left has elements
        while (i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }

        // PHASE 3: Copy remaining elements from right subarray (if any)
        // This runs when left subarray is exhausted but right has elements
        while (j <= end)
        {
            temp.push_back(arr[j]);
            j++;
        }

        // PHASE 4: Copy merged result back to original array
        // Important: Start copying from index 'st', not 0!
        for(int k = 0; k < temp.size(); k++){
            arr[k + st] = temp[k]; // arr[st], arr[st+1], arr[st+2], ...
        }
    }

    /**
     * MERGE SORT FUNCTION - Recursive Divide and Conquer
     * Purpose: Recursively divides array and calls merge to combine
     * Recursive Case: Split into two halves and sort each
     */
    void mergeSort(vector<int> &nums, int st, int end)
    {
        // BASE CASE: If subarray has 0 or 1 element, it's already sorted
        if (st < end)
        {
            // Calculate midpoint (avoids integer overflow)
            int mid = st + (end - st) / 2;

            // DIVIDE & CONQUER
            // Recursively sort left half: indices [st, mid]
            mergeSort(nums, st, mid);
            
            // Recursively sort right half: indices [mid+1, end]
            mergeSort(nums, mid + 1, end);

            // COMBINE: Merge the two sorted halves
            merge(nums, st, mid, end);
        }
        // If st >= end, do nothing (base case - already sorted)
    }

    /**
     * MAIN SORTING FUNCTION
     * Returns: Sorted vector (same reference, but sorted in-place)
     */
    vector<int> sortArray(vector<int> &nums)
    {
        // Start merge sort with full array: indices 0 to size-1
        mergeSort(nums, 0, nums.size() - 1);
        return nums; // Return the now-sorted array
    }
};

/**
 * EXAMPLE EXECUTION TRACE for [5, 2, 3, 1]:
 * 
 * mergeSort(0,3): [5,2,3,1]
 * ├─ mergeSort(0,1): [5,2]
 * │  ├─ mergeSort(0,0): [5] → base case, return
 * │  ├─ mergeSort(1,1): [2] → base case, return  
 * │  └─ merge(0,0,1): merge [5] and [2] → [2,5]
 * ├─ mergeSort(2,3): [3,1]  
 * │  ├─ mergeSort(2,2): [3] → base case, return
 * │  ├─ mergeSort(3,3): [1] → base case, return
 * │  └─ merge(2,2,3): merge [3] and [1] → [1,3]
 * └─ merge(0,1,3): merge [2,5] and [1,3] → [1,2,3,5]
 */

int main()
{
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    
    cout << "Original: ";
    for(int x : nums) cout << x << " ";
    cout << endl;
    
    vector<int> sorted = sol.sortArray(nums);
    
    cout << "Sorted: ";
    for(int x : sorted) cout << x << " ";
    cout << endl;
    
    return 0;
}