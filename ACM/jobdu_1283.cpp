// 题目描述：
//     在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符。
// 输入：
//     输入有多组数据
//     每一组输入一个字符串。
// 输出：
//     输出第一个只出现一次的字符下标，没有只出现一次的字符则输出-1。
// 样例输入：
//     ABACCDEFF
//     AA
// 样例输出：
//     1
//     -1

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	string input;
	int char_count[255];
	int i;
	int found;
	while (cin >> input) {
		for (i= 0; i < 255; ++i)
			char_count[i] = 0;
		for (i = 0; i < input.size(); ++i) {
			char_count[input[i]]++;
		}
		found = 0;
		for (i = 0; i < input.size(); ++i) {
			if (char_count[input[i]] == 1) {
				found = 1;
				cout << i << endl;
				break;
			}
		}
		if (found == 0) {
			cout << -1 << endl;
		}
	}
	return 0;
}