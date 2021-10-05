// https://leetcode.com/problems/merge-intervals/
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
// and return an array of the non - overlapping intervals that cover all the intervals in the input.
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std;
class Solution {
public:
    bool isIntersecting(vector<int> c, vector<int> n)
        {

        return (c[1] >= n[0]);

        }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() <= 1)
            return intervals;
        // Step 1: Sort the input intervals
        sort(intervals.begin(), intervals.end());
        // Step2: Traverse the sorted intervals pairwise
        vector<vector<int>> r;
        vector<int> curr, next;
        curr = intervals[0];
        next = intervals[1];
        for (int i = 0; i < intervals.size() - 1; i++)
            {
            // cout << "curr: " << curr[0] << "\t" << curr[1] << endl;
            // cout << "next: " << next[0] << "\t" << next[1] << endl;
            if (isIntersecting(curr, next))
                {
                curr[1] = max(curr[1], next[1]);
                if (i + 1 == intervals.size() - 1)
                    {
                    r.push_back(curr);
                    return r;
                    }

                next = intervals[i + 2];
                }
            else
                {
                r.push_back(curr);
                curr = next;

                if (i == intervals.size() - 1)
                    {
                    r.push_back(curr);
                    return r;
                    }
                if (i + 2 < intervals.size())
                    next = intervals[i + 2];
                }
            }
        r.push_back(next);
        return r;
        }
    };

int main()
    {
    vector<vector<int> > intervals{ {1,4},{4,5} };
    Solution o;
    vector<vector<int>> r = o.merge(intervals);

    for (auto a : r)
        {
        cout << a[0] << "\t" << a[1] << "\n";
        }

    }