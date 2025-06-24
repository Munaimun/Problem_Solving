// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


// Input: s = "IceCreAm"
// Output: "AceCreIm"

// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
// Solution:
const reverseVowels = (s) => {
    let l = 0, r = s.length - 1; // r staring at the end
    let res = s.split("");

    //If vowels were an array, the includes method (vowels.includes(res[l])) would require checking every element one by one (O(n) complexity).
    //Since vowels is a Set, the has method (vowels.has(res[l])) runs in O(1) constant time, making it much faster.
    let vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])

    while (l < r) {
        if (!vowels.has(res[l])) {
            l++
        } else if (!vowels.has(res[r])) {
            r--;
        } else {
            // replacing them
            let temp = res[r];
            res[r] = res[l];
            res[l] = temp;
            l++;
            r--;
        }
    }
    return res.join('')
};