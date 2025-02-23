// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

// Solution:
const plusOne = (digits) => {
    // Iterate from the last digit to the first digit (right to left)
    for (let i = digits.length - 1; i >= 0; i--) {

        // If adding 1 does not result in a carry (not 10)
        if (digits[i] + 1 !== 10) {
            digits[i] += 1; // Simply add 1 to the digit
            return digits;
        }

        // If the digit is 9, set it to 0 (carry over)
        digits[i] = 0;

        // If we reached the first digit (i === 0) and it's also 9
        // We need to insert 1 at the beginning since all digits are 0 now
        if (i === 0) {
            digits.unshift(1);
        }
    }

    return digits;
};
