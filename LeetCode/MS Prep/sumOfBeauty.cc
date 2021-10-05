#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pq_max;
        priority_queue<int> pq_min;
        int N = nums.size();
        int flags[N][2];
        int beauty[N];
        beauty[0] = 0;
        beauty[N - 1] = 0;
        flags[0][0] = 0;
        flags[0][1] = 0;
        flags[N - 1][0] = 0;
        flags[N - 1][1] = 0;
        
        for (int i = 0; i < N; i++)
            {
            if (1 <= i && i <= N - 2)
                beauty[i] = (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]);
            }


        for (int i = 0; i < N; i++)
            {
            if (!pq_min.empty() && pq_min.top() == nums[i])
                flags[i][0] = 0;
            else {
                pq_min.push(nums[i]);
                if (1 <= i && i <= N - 2)
                    {
                     flags[i][0] = (pq_min.top() == nums[i])?1:0;
                    }
                }
            }

        for (int i = N-1; i >= 0; i--)
            {
            if (!pq_max.empty() && pq_max.top() == nums[i])
                flags[i][1] = 0;
            else {
                pq_max.push(nums[i]);
                if (1 <= i && i <= N - 2)
                    {
             
                    flags[i][1] = (pq_max.top() == nums[i]) ? 1 : 0;
                    }
                }
            }
 
        cout << endl;
        
        int sum_beauty = 0;

        for (int i = 1; i <= N - 2; i++)
            { 
            beauty[i] += (flags[i][0] && flags[i][1]) ? 1 : 0;
            sum_beauty += beauty[i];
            }
        return sum_beauty;
        }
    };

int main()
    {
    vector<int> nums{ 1,2,3,4 };

    Solution obj;
    cout << obj.sumOfBeauties(nums);
    }