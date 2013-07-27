// 题目描述：
//     一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
// 输入：
//    输入可能包含多个测试样例，对于每个测试案例，
//     输入包括一个整数n(1<=n<=70)。
// 输出：
//     对应每个测试案例，
//     输出该青蛙跳上一个n级的台阶总共有多少种跳法。
// 样例输入：
//     5
// 样例输出：
//     8

#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int n, i;
	long long f[72];
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i <= 71; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
	while (cin >> n) {
		cout << f[n + 1] << endl;
	}
	return 0;
}