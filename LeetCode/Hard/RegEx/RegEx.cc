//https://github.com/vinceyuan/leetcode_solutions/blob/master/N010RegEx/N010RegEx.cpp
#include "RegEx.h"
#include <iostream>

namespace RegEx {
	using namespace std;
    
	void test() {
		V2::Solution n010;
		cout << "RegEx:\t\t";
		cout << n010.isMatch(string("aa"), string("a")) << ' ';
		cout << n010.isMatch(string("aa"), string("aa")) << ' ';
		cout << n010.isMatch(string("aaa"), string("aa")) << ' ';
		cout << n010.isMatch(string("aaa"), string("ab*a")) << ' ';
		cout << n010.isMatch(string("aa"), string("a*")) << ' ';
		cout << n010.isMatch(string("aa"), string(".a")) << ' ';
		cout << n010.isMatch(string("ab"), string(".*")) << ' ';
		cout << n010.isMatch(string("aab"), string("c*a*b")) << ' ';
		cout << n010.isMatch(string("aaaaaaaaaaaaab"), string("a*a*a*a*a*a*a*a*a*a*a*a*b")) << ' ';
		cout << n010.isMatch(string("aaaaaaaaaaaaab"), string("a*a*a*a*a*a*a*a*a*a*c"));
		cout << endl;
	}
}
using namespace RegEx ;
int main(){
   test(); 
}