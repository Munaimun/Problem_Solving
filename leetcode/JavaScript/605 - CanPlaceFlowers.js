// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

// Input: flowerbed = [1, 0, 0, 0, 1], n = 1
// Output: true

// Solution:
const canPlaceFlowers = (flowerbed, n) => {
    if (n === 0) return true; // If no flowers need to be placed, return true immediately

    let i = 0;
    while (i < flowerbed.length) {
        // Check if the current plot is empty and its adjacent plots are also empty or out of bounds
        if (flowerbed[i] === 0 &&
            (i === 0 || flowerbed[i - 1] === 0) && // Check left neighbor (or out of bounds)
            (i === flowerbed.length - 1 || flowerbed[i + 1] === 0)) { // Check right neighbor (or out of bounds)

            flowerbed[i] = 1; // Place a flower
            n--; // Decrease the count of flowers that need to be placed

            if (n === 0) return true; // If all flowers are placed, return true

            i++; // Skip the next plot to ensure no adjacent planting
        }
        i++; // Move to the next plot
    }

    return false; // If not enough space was found, return false
};

