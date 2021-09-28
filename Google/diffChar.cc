// Interview Questions
// Given two strings where one string has exactly one more character than the other string. 
// Code to find that additional character.
#include <iostream>
    using namespace std;
int main()
{
    string s1, s2;
    s1 = "aaaaaaaabbbbbbbcauwouqufpj";
    s2 = "aaaaaaaabbbbbbbcazuwouqufpj";
    int A[26] = {0};
    int len = s1.size();
    int i = 0;
    while (len--)
    {
        A[s1[i] - 97]++;
        i++;
    }
    len = s2.size();
    i = 0;
    while (len--)
    {
        A[s2[i] - 97]--;
        i++;
    }

    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (A[i] == -1)
        {
            ch = i + 97;
            cout << ch << "\n";
            break;
        }
    }
}
