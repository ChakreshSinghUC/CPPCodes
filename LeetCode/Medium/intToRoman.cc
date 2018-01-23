/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    string intToRoman(int num)
    {

        vector<int> v;
        string s;
        while (num != 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }

        reverse(v.begin(), v.end());
        int place = v.size() - 1;
        for (int i : v)
        {
            switch (place)
            {
            case 0:
                //I placed before V or X indicates one less, so four is IV (one less than 5) and 9 is IX (one less than 10)
                if (i == 4)
                    s += "IV";
                else if (i == 9)
                    s += "IX";
                else if (i < 4 && i > 0)
                    for (int j = 0; j < i; j++)
                        s += "I";
                else if (i < 9 && i > 5)
                {
                    s += "V";
                    for (int j = 0; j < (i - 5); j++)
                        s += "I";
                }
                else if (i == 5)
                    s += "V";
                break;
            case 1:
                //X placed before L or C indicates ten less, so forty is XL (10 less than 50) and 90 is XC (ten less than a hundred).
                if (i == 4)
                    s += "XL";
                else if (i == 9)
                    s += "XC";
                else if (i == 5)
                    s += "L";
                else if (i < 4 && i > 0)
                {
                    for (int j = 0; j < i; j++)
                        s += "X";
                }
                else if (i < 9 && i > 5)
                {
                    s += "L";
                    for (int j = 0; j < i - 5; j++)
                        s += "X";
                }
                break;
            case 2:
                //C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand).
                if (i == 4)
                    s += "CD";
                else if (i == 9)
                    s += "CM";
                else if (i == 5)
                    s += "D";
                else if (i < 4 && i > 0)
                {
                    for (int j = 0; j < i; j++)
                        s += "C";
                }
                else if (i < 9 && i > 5)
                {
                    s += "D";
                    for (int j = 0; j < i - 5; j++)
                        s += "C";
                }
                break;
            case 3:
                if (i < 5 && i > 0)
                {
                    for (int j = 0; j < i; j++)
                        s += "M";
                }
                break;
            default:
                break;
            }
            place--;
        }
        return (s);
    }
};

int main()
{
    Solution obj;
    //  for (int i = 1; i <= 9; i++)
    cout <<  obj.intToRoman(1803) << endl;
}