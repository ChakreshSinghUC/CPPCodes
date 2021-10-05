
#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    int countLetters(string S)
    {

        if (S.length() <= 1)
            return S.length();

        int sum = 0;
        int temp_sum = 1;

        int k = 0;

        while (k < S.length() )
        {

            if (S[k] == S[k + 1])
                temp_sum++;
            else
            {
                sum += temp_sum * (temp_sum+1) / 2;
                cout << S[k] << "\t" << temp_sum << endl;
                temp_sum = 1;
            }
            k++;
        }

        // sum += temp_sum * (temp_sum) / 2;
        return sum;
    }
};

int main()
{
    string s = "aaaaaaaaaa";
    Solution obj;
    cout << obj.countLetters(s);
}