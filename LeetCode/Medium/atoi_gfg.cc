// https://github.com/vinceyuan/leetcode_solutions/blob/master/N008StringToInt/N008StringToInt.h
// https://leetcode.com/problems/string-to-integer-atoi/description/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		size_t length = str.length();
		if (length == 0)
			return 0;

		long long value = 0;
		int index = 0, indexE = -1;
		bool isNeg = false, foundE = false;
		while(str[(size_t)index] == ' ' && index < (int)length)
			index++;
		if (str[(size_t)index] == '-') {
			isNeg = true;
			index++;
		} else if (str[(size_t)index] == '+') {
			index++;
		}
		for (; index < (int)length; index++) {
			if (str[(size_t)index] == 'e' || str[(size_t)index] == 'E')	{
				foundE = true;
				indexE = index;
				break;
			} else if (str[(size_t)index] >= '0' && str[(size_t)index] <= '9') {
				value = value * 10 + str[(size_t)index] - '0';
				if (!isNeg) {
					if (value > INT_MAX) {
						return INT_MAX;
					}
				} else {
					if (-value < INT_MIN) {
						return INT_MIN;
					}
				}
			} else {
				break;
			}
		}

		int valueAfterE = 0;
		if (foundE) {
			for (indexE = indexE + 1; indexE < (int)length; indexE++) {
				valueAfterE = valueAfterE * 10 + str[(size_t)indexE] - '0';
			}
		}

		long long oldValue = value;
		for (int i = 0; i < valueAfterE; i++) {
			value *= 10;
			if (!isNeg) {
				if (value > INT_MAX) {
					value = oldValue;
					break;
				}
			} else {
				if (-value < INT_MIN) {
					value = oldValue;
					break;
				}
			}
		}
		if (isNeg)
			value = -value;
		if (value > INT_MAX)
			value = INT_MAX;
		if (value < INT_MIN)
			value = INT_MIN;
		return (int)value;
	}
};
int main()
{
    Solution o;
    cout << endl
         << o.myAtoi("  0010");
}