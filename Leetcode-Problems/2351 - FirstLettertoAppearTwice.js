// Given a string s consisting of lowercase English letters, return the first letter to appear twice.

// Note:
//A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
//s will contain at least one letter that appears twice.

// Input: s = "abccbaacz"
// Output: "c"

// Solution: 
const repeatedCharacter = (s) => {
    let myArr = s.split('')
    let map = {}

    for (let i = 0; i < myArr.length; i++) {
        if (map[myArr[i]] !== undefined) { // <-- check if the letter is in the map, if yes then return it
            return myArr[i]
        } else {
            map[myArr[i]] = i; // <-- if it is not in the map, then put it in map
        }
    }

    return undefined;
};
