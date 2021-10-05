#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max_len = INT_MIN;
        if (arr.size() < 2) return arr.size();
        int curr_len = 1;

        bool prev_flag = (arr[0] < arr[1]);
        for (int i = 1; i < arr.size() - 1; i++)
            {

            if (prev_flag ^ (arr[i] < arr[i + 1]))
                {
                prev_flag = !prev_flag;
                curr_len++;
                }
            else
                {
                max_len = max(max_len, curr_len);
                curr_len = 1;
                }


            }
        max_len = max(max_len, curr_len);
        return max_len;
        }
    };
int main()
    {
    vector<int> vec{ 4,8,11,16 };

    Solution obj;

    cout << obj.maxTurbulenceSize(vec);
    }