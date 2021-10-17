    /*
    #include<queue>
    #include<vector>
    #include<stack>
    #include<iostream>

    using namespace std;
    */
    class Solution
    {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            vector<vector<int>> intervals;

            int N=(int) startTime.size();
            for(int i = 0; i<N; i++)
            {
                vector<int> row;
                row.push_back(startTime[i]);
                row.push_back(endTime[i]);
                row.push_back(profit[i]);
                intervals.push_back(row);
            }
    //         sort intervals w.r.t. start times
            sort(intervals.begin(), intervals.end());

            auto comp=[](priority_queue<pair<int, int>> p, priority_queue<pair<int, int>> q){return p.top().first<=q.top().first;};
    //        priority queue of priority queues of pairs (end time and total profit after including all valid intervals for the endTime)
            priority_queue<priority_queue<pair<int,int>>, vector<priority_queue<pair<int, int>>>, decltype(comp) > pq_pq (comp); 

            priority_queue<pair<int,int>> pq;
            pq.push({intervals[0][2],intervals[0][1]});  //endtime and profit
            pq_pq.push(pq);
            int max_profit=INT_MIN;

            stack<priority_queue<pair<int, int>>> stk_pq;
            for(int i=1;i<N;i++){ 
                int t = pq_pq.size();
            while(t--){
                //a new interval can be added if its starttime is greater than or equal to the endtime of last interval
                if(pq_pq.top().top().second<=intervals[i][0]) 
                {
                int p = pq_pq.top().top().first;
                    p +=intervals[i][2];

                    priority_queue<pair<int, int>> pq;
                    pq.push({p, intervals[i][1]});
                    pq_pq.push(pq);
                   break;
                }
                    stk_pq.push(pq_pq.top());
                    pq_pq.pop();


               }
                if(!stk_pq.empty())
                {
                    priority_queue<pair<int,int>> p;
                    p.push({intervals[i][2], intervals[i][1]}); 
                    pq_pq.push(p); 
                }
             while(!stk_pq.empty()){
                        pq_pq.push(stk_pq.top());
                        stk_pq.pop();
                    }
            }


            return pq_pq.top().top().first;
        }
    };
    /*
    int main()
    {
        Solution o;

        vector<int> startTime{1,2,3,3};
        vector<int> endTime{3, 4, 5, 6};
        vector<int> profit{50, 10, 40, 70};
        {
            cout << o.jobScheduling(startTime, endTime, profit);
        }
    }
    */