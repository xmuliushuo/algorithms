// 题目描述：
//     输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
// 输入：
//     输入可能包含多个测试样例。
//     对于每个输入文件，第一行输入一个整数T，代表测试样例的数量。对于每个测试样例输入为一个整数。
//     。n保证是int范围内的一个整数。
// 输出：
//     对应每个测试案例，
//     输出一个整数，代表输入的那个数中1的个数。
// 样例输入：
//     3
//     4
//     5
//     -1
// 样例输出：
//     1
//     2
//     32

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	int T;
	int input;
	int count;
	int i;
	while (cin >> T) {
		for (i = 0; i < T; ++i) {
			scanf("%d", &input);
			count = 0;
			while (input) {
				++count;
				input &= (input - 1);
			}
			// cout << count << endl;
			printf("%d\n", count);
		}
	}
	return 0;
}