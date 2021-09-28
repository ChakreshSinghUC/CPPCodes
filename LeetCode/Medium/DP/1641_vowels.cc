#include<iostream>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        return countVowelStringUtil(n, 1);
    }

    int countVowelStringUtil(int n, int vowels) {
        if (n == 0)
            return 1;
        int result = 0;
        for (int i = vowels; i <= 5; i++)
        {
            result += countVowelStringUtil(n - 1, i);
        }
        return result;
    }   

     int __countVowelStrings(int n) {
         
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }   
};

int main()
{
    Solution obj;
    cout<<obj.countVowelStrings(5)<<endl;

    cout << obj.__countVowelStrings(5);

}