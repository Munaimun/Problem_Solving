/*
QUICKSORT ALGORITHM IMPLEMENTATION



Time Complexity: O(n²) - When pivot is always smallest/largest element (sorted/reverse sorted array)
Space Complexity: O(n) - Due to recursion stack depth in worst case

Algorithm: Divide and Conquer approach using Lomuto Partition Scheme
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Call recursive quicksort on entire array
        quickSort(nums, 0, nums.size() - 1);
        return nums; // Return sorted array
    }
    
private:
    // Recursive quicksort function - divides array and sorts subarrays
    void quickSort(vector<int>& nums, int st, int end) {
        // Base case: if start >= end, subarray has 0 or 1 elements (already sorted)
        if (st < end) {
            // Partition array and get pivot's final position
            int pivotIdx = partition(nums, st, end);
            
            // Recursively sort left subarray (elements < pivot)
            quickSort(nums, st, pivotIdx - 1);
            
            // Recursively sort right subarray (elements > pivot)
            quickSort(nums, pivotIdx + 1, end);
        }
    }
    
    // Partition function using Lomuto scheme - rearranges array around pivot
    int partition(vector<int>& nums, int st, int end) {
        // Choose last element as pivot
        int pivot = nums[end];
        
        // idx tracks the boundary of elements <= pivot
        // Initially set to st-1 (no elements processed yet)
        int idx = st - 1;
        
        // Traverse array from start to end-1
        for (int j = st; j < end; j++) {
            // If current element is <= pivot, it belongs in left partition
            if (nums[j] <= pivot) {
                idx++; // Expand left partition boundary
                swap(nums[j], nums[idx]); // Move element to left partition
            }
            // Elements > pivot automatically stay in right partition
        }
        
        // Place pivot in its correct final position
        idx++; // Move to position where pivot should be
        swap(nums[idx], nums[end]); // Swap pivot to correct position
        
        // Return pivot's final index
        return idx;
    }
};

// Test the implementation
int main() {
    Solution solve;
    vector<int> arr = {5, 2, 3, 1};
    
    cout << "Original: ";
    for (int i : arr) cout << i << " ";
    cout << endl;
    
    vector<int> result = solve.sortArray(arr);
    
    cout << "Sorted: ";
    for (int i : result) cout << i << " ";
    cout << endl;
    
    return 0;
}