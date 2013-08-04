// 题目描述：
// 		一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
// 输入：
// 		输入可能包含多个测试样例，对于每个测试案例，
// 		输入包括一个整数n(1<=n<=50)。
// 输出：
// 		对应每个测试案例，
// 		输出该青蛙跳上一个n级的台阶总共有多少种跳法。
// 样例输入：
// 		6
// 样例输出：
// 		32
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
	int n;
	long long result;
	while (cin >> n) {
		result = (long long)pow(2, n - 1);
		cout << result << endl;
	}
	return 0;
}