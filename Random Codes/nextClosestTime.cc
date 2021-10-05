// https://leetcode.com/explore/interview/card/google/67/sql-2/471/
// Next Closest Time
// Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits.
// There is no limit on how many times a digit can be reused.
// You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9"
// are all invalid.
// Example 1:
// Input: "19:34"
// Output: "19:39"
// Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
// It is not 19:33, because this occurs 23 hours and 59 minutes later.
// Example 2:
// Input: "23:59"
// Output: "22:22"
// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
// It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution
{
  public:
    string nextClosestTime(string time)
    {
        vector<int> digits, temp;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int i = 0; i < time.length(); i++)
        {
            if (i != 2)
            {
                digits.push_back(time[i] - 48);
                smallest = min(smallest, time[i] - 48);
                largest = max(largest, time[i] - 48);
            }
        }
        temp = digits;
        sort(temp.begin(), temp.end());
        for (auto i : temp)
        {
            if (i > digits[3])
            {
                time[4] = 48 + i;
                return time;
            }
        }
        for (auto i : temp)
        {
            if (i > digits[2] && i < 6)
            {
                time[3] = 48 + i;
                time[4] = smallest + 48;
                return time;
            }
        }
        for (auto i : temp)
        {
            if (i > digits[1] && ((i < 4 && digits[0] == 2) || (i < 10 && digits[0] < 2)))
            {
                time[1] = i + 48;
                time[3] = smallest + 48;
                time[4] = smallest + 48;
                return time;
            }
        }
        for (auto i : temp)
        {
            if (i > digits[0] && i < 3)
            {
                time[0] = i + 48;
                time[1] = smallest + 48;
                time[3] = smallest + 48;
                time[4] = smallest + 48;
                return time;
            }
        }

        time[0] = smallest + 48;
        time[1] = smallest + 48;
        time[3] = smallest + 48;
        time[4] = smallest + 48;
        //if last digit is smaller than the largest, just increae it to the next biggest number.

        return time;
    }
};
int main()
{
    Solution obj;
    string t = "13:55";
    cout << "TIME: " << obj.nextClosestTime(t);
}