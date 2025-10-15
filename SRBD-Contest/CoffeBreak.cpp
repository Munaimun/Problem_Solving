#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int h, int m)
{
    string time = "";

    time += (h / 10) + '0';
    time += (h % 10) + '0';
    time += (m / 10) + '0';
    time += (m % 10) + '0';

    // checking if its a palindrome
    return time[0] == time[3] && time[1] == time[2];
}

string findNextBreak(string curTime)
{
    // taking the hour and minute from the current time
    int hour = (curTime[0] - '0') * 10 + (curTime[1] - '0'); // multiply by 10 bcoz its in the 10s place
    int minute = (curTime[3] - '0') * 10 + (curTime[4] - '0');

    // Try all times from current until we find palindrome
    for (int i = 1; i <= 1440; i++)
    {
        minute++;

        if (minute >= 60)
        {
            minute = 0;
            hour++;
            if (hour >= 24)
                hour = 0;
        }

        if (isPalindrome(hour, minute))
        {
            string res = "";

            res += (hour / 10) + '0';   // take the first digit of hour
            res += (hour % 10) + '0';   // take the second digit of hour
            res += ':';                 // for HH:MM
            res += (minute / 10) + '0'; // take the first digit of minute
            res += (minute % 10) + '0'; // take the second digit of minute

            return res;
        }
    }

    return "00:00";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string time;
        cin >> time;


        cout << findNextBreak(time) << endl;
    }

    return 0;
}