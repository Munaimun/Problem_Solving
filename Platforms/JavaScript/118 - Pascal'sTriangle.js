// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Solution:
const generate = (numRows) => {
    // Edge case: If numRows is less than 1, return an empty array.
    if (numRows < 1) return [];

    // Edge case: If numRows is exactly 1, return the base case of Pascal's Triangle ([[1]]).
    if (numRows === 1) return [[1]];

    // Initialize the triangle with the first row, which is always [1].
    const triangle = [[1]];

    // Iterate to build each subsequent row of the triangle.
    for (let i = 1; i < numRows; i++) {
        // Get the previous row to calculate the current row.
        let prevRow = triangle[i - 1];

        // Initialize the current row with the first element as 1.
        let curRow = [1];

        // Calculate the middle elements of the current row.
        // Each element is the sum of the two elements directly above it from the previous row.
        for (let j = 1; j < prevRow.length; j++) {
            curRow[j] = prevRow[j] + prevRow[j - 1];
        }

        // The last element of each row is always 1.
        curRow.push(1);

        // Add the current row to the triangle.
        triangle.push(curRow);
    }

    return triangle;
};