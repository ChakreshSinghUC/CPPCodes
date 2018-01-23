//https://github.com/vinceyuan/leetcode_solutions/blob/master/N010RegEx/N010RegEx.h
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
namespace RegEx
{
using namespace std;
namespace V1
{
class Solution
{
    void expandFirstStar(size_t slength, string &p, vector<string> &patterns)
    {
        // cout << " Checking " << p << endl;
        size_t plength = p.length();
        size_t nstar = 0;
        for (size_t i = 0; i < plength; i++)
        {
            if (p[i] == '*')
                nstar++;
        }

        int maxSpace = (int)((int)slength - (int)((int)plength - 2 * (int)nstar));
        if (maxSpace < 0)
            return;

        size_t starIndex = p.find('*');
        if (starIndex == 0 || starIndex == string::npos)
            return;
        char c = p[starIndex - 1];
        string pre = p.substr(0, starIndex - 1);
        string post = p.substr(starIndex + 1, plength - starIndex - 1);
        for (int i = 0; i <= maxSpace; i++)
        {
            string str = pre;
            for (int j = 0; j < i; j++)
                str = str + c;
            str = str + post;
            patterns.push_back(str);
        }
    }

  public:
    bool isMatch(string s, string p)
    {
        // cout << p << " " << endl;
        size_t slength = s.length();
        size_t plength = p.length();
        size_t firstStar = p.find('*');
        if (firstStar == string::npos)
        {
            if (slength != plength)
                return false;
            size_t i = 0;
            do
            {
                if (s[i] != p[i] && p[i] != '.')
                    return false;
            } while (++i < slength);
            return true;
        }

        // Check chars before the first star
        for (size_t i = 0; i < firstStar - 1; i++)
        {
            if (s[i] != p[i] && p[i] != '.')
                return false;
        }

        size_t lastStar = p.rfind('*');
        // Check chars after the last star
        for (size_t i = 0; i < plength - lastStar - 1; i++)
        {
            if (i > slength - 1 || (s[slength - 1 - i] != p[plength - 1 - i] && p[plength - 1 - i] != '.'))
                return false;
        }

        // Has star, need to expand patterns
        vector<string> patterns;
        expandFirstStar(slength, p, patterns);
        for (vector<string>::iterator itor = patterns.begin();
             itor != patterns.end(); itor++)
        {
            if (isMatch(s, *itor))
                return true;
        }
        return false;
    }
};
} // End of V1

namespace V2
{
class Solution
{
    size_t findSubstrWithDot(string &s, string &substr, size_t index)
    {
        //cout << "findSubstrWithDot: " << substr << ' ' << index;
        size_t i = index, len = s.length(), lenSub = substr.length();
        for (; i < len - lenSub + 1; i++)
        {
            bool found = true;
            for (size_t j = 0; j < lenSub; j++)
            {
                if (substr[j] != '.' && s[i + j] != substr[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                return i;
            }
        }
        return string::npos;
    }

    bool hasAllTokens(string &s, string &p, size_t startS, size_t startP)
    {
        // Check if p's substrings divided by * exist in s
        size_t i = startS, j = startP, lenP = p.length();
        size_t start = j, end = j;
        size_t indexOfPreviousToken = i;
        while (start < lenP && end < lenP)
        {
            while (start + 1 < lenP && (p[start + 1] == '*'))
                start += 2;
            if (start < lenP)
            {
                end = start;
                while (end + 1 < lenP && p[end + 1] != '*')
                    end++;
                if (end + 1 == lenP)
                    end++;
                if (end <= lenP && end > start)
                {
                    // Found a token [start, end - 1]
                    // Check if this token exists in s
                    string substr = p.substr(start, end - start);
                    indexOfPreviousToken = findSubstrWithDot(s, substr, indexOfPreviousToken);
                    if (indexOfPreviousToken == string::npos)
                    {
                        return false;
                    }
                    indexOfPreviousToken += end - start;
                    start = end + 2;
                    end = end + 2;
                }
            }
        }
        return true;
    }

    bool isMatchInternal(string &s, string &p, size_t startS, size_t startP)
    {
        size_t i = startS, j = startP, lenS = s.length(), lenP = p.length();
        if (lenS - i == 0 && lenP - j == 0)
            return true;
        size_t n = (size_t)count(p.begin() + (long)startP, p.end(), '*');
        if (lenS - i < lenP - 2 * n - j)
            return false;
        for (; j < lenP; i++, j++)
        {
            if (j + 1 < lenP)
            {
                if (p[j + 1] != '*')
                {
                    if (p[j] != '.' && p[j] != s[i])
                    {
                        return false; // not match
                    }
                }
                else
                {
                    if (!hasAllTokens(s, p, i, j))
                        return false;
                    // Expand *
                    // 0 char
                    if (isMatchInternal(s, p, i, j + 2))
                        return true;
                    // k chars
                    for (size_t k = 1; k <= lenS - i - (lenP - j - 2 * n); k++)
                    {
                        bool matched = true;
                        for (size_t q = 0; q < k; q++)
                        {
                            if (p[j] != '.' && p[j] != s[i + q])
                            {
                                matched = false;
                                break;
                            }
                        }
                        if (matched)
                            if (isMatchInternal(s, p, i + k, j + 2))
                                return true;
                    }
                    // 0 char ~ k chars not match, return false
                    return false;
                }
            }
            else
            {
                if (p[j] != '.' && p[j] != s[i])
                    return false;
            }
        }
        if (i == lenS && j == lenP)
            return true;
        return false;
    }

  public:
    bool isMatch(string s, string p)
    {
        // Scan from begin
        return isMatchInternal(s, p, 0, 0);
    }
};
} // End of V2

void test();
}