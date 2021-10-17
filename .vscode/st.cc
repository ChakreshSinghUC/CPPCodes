
#include<iostream>

using namespace std;

class Solution
{
public:
    bool isOneEditDistance(string s, string t) {
        return helper(s,t,1);
    }
      bool helper(string s, string t, int cnt) 
      {
          int s_len = (int) s.length();
          int t_len = (int) t.length();
        
        if(abs(s_len-t_len)>1)
            return false;
        if(min(s_len,t_len)==0 && max(s_len,t_len)==1)
            return true;
            int idx=0; 
            int miss_cnt=cnt;
        if(s_len==t_len){
            
            while(idx<s_len){
                if(s[idx]!=t[idx]&&miss_cnt<1)
                {
                    miss_cnt++;
                }  
                else if(s[idx]!=t[idx]&&miss_cnt==1){
                    return false;
                } 
                idx++;
            }
        }
            else
            {
                int n=min(s_len, t_len);
                while(idx<n){
                    if(s[idx]!=t[idx]){
                        return helper(s.substr(idx, s.length() - idx), t.substr(idx, t.length() - idx+1), 0)
                             ||helper(s.substr(idx, s.length() - idx+1), t.substr(idx, t.length() - idx), 0);
                    }
                    idx++;
                }
                
            }
            return true;
      }
};