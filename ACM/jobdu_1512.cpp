// 题目描述：
//     用两个栈来实现一个队列，完成队列的Push和Pop操作。
//     队列中的元素为int类型。

// 输入：
//     每个输入文件包含一个测试样例。
//     对于每个测试样例，第一行输入一个n(1<=n<=100000)，代表队列操作的个数。
//     接下来的n行，每行输入一个队列操作：
//     1. PUSH X 向队列中push一个整数x(x>=0)
//     2. POP 从队列中pop一个数。

// 输出：
//     对应每个测试案例，打印所有pop操作中从队列pop中的数字。如果执行pop操作时，队列为空，则打印-1。

// 样例输入：
//     3
//     PUSH 10
//     POP
//     POP

// 样例输出：
//     10
//     -1

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;
stack<int> stack1, stack2;
int main()
{
	int n;
	cin >> n;
	string temp;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (temp == "PUSH") {
			cin >> num;
			stack1.push(num);
		}
		else {
			if (!stack2.empty()) {
				cout << stack2.top() << endl;
				stack2.pop();
				continue;
			}
			while (!stack1.empty()) {
				num = stack1.top();
				stack1.pop();
				stack2.push(num);
			}
			if (stack2.empty()) cout << -1 << endl;
			else {
				cout << stack2.top() << endl;
				stack2.pop();
			}
		}
	}
	return 0;
}
