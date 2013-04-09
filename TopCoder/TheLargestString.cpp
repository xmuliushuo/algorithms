#include "stdafx.h"


#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;



class TheLargestString
{
public:
    string find(string s, string t);
};

string TheLargestString::find(string s, string t)
{
	int length = s.size();
	vector<string> ans(length);
	ans[length - 1] = s.substr(length - 1, 1) + t[length - 1];
	for (int i = length - 2 ; i >= 0; --i) {
		string temp1 = ans[i + 1];
		string temp2 = s[i] + temp1.substr(0, temp1.size() / 2) + t[i] + temp1.substr(temp1.size() / 2, temp1.size() / 2);
		ans[i] = (max(temp1, temp2));
	}
	return ans[0];
}

// int main()
// {
// 	TheLargestString temp;
// 	int ipause;
// 	cout << temp.find("a", "a") << endl;
// 	cout << temp.find("ab", "zy") << endl;
// 	cout << temp.find("bb", "ab") << endl;
// 	cout << temp.find("abacaba", "zzzaaaa") << endl;
// 	cout << temp.find("abbabbabbababaaaabbababab", "bababbaabbbababbbbababaab") << endl;
// 	cin >> ipause;
// 	return 0;
// }