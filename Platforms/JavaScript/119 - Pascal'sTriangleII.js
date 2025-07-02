/**
*Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangl
*In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*
* Time Complexity: O(rowIndex²) - Due to the nested loop for updating elements.
* Space Complexity: Achieved O(rowIndex) - We only store one row instead of the entire triangle.
*/
const getRow = (rowIndex) => {
    let row = [1]; // Initialize the first row as [1]

    // Iterate from row 1 to rowIndex, building the row step by step
    for (let i = 1; i <= rowIndex; i++) {
        row.push(1); // Add a new '1' at the end since every row starts and ends with 1

        // Update row values from right to left to avoid overwriting values
        for (let j = i - 1; j > 0; j--) {
            row[j] = row[j - 1] + row[j]; // Compute new value using previous row
        }
    }

    return row; // Return the final computed row
};
