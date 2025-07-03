// Time Complexity: O(n), where n is the input number
// Space Complexity: O(n), since we're storing n strings in the output vector

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Generates the FizzBuzz sequence from 1 to n
    vector<string> fizzBuzz(int n)
    {
        vector<string> s;
        s.reserve(n); // Reserve space for n elements to optimize memory allocation

        // Iterate through numbers from 1 to n
        for (int i = 1; i <= n; i++)
        {
            // Check if number is divisible by both 3 and 5
            if (i % 3 == 0 && i % 5 == 0)
            {
                s.push_back("FizzBuzz"); // Add "FizzBuzz"
            }
            // Check if number is divisible by 3 only
            else if (i % 3 == 0)
            {
                s.push_back("Fizz"); // Add "Fizz"
            }
            // Check if number is divisible by 5 only
            else if (i % 5 == 0)
            {
                s.push_back("Buzz"); // Add "Buzz"
            }
            else
            {
                s.push_back(to_string(i)); // Otherwise, add the number as a string
            }
        }

        return s;
    }
};

int main()
{
    Solution sol;

    vector<string> result = sol.fizzBuzz(3);

    // Print the results separated by spaces
    for (const string &str : result)
        cout << str << " ";
    cout << "\n";

    return 0;
}
