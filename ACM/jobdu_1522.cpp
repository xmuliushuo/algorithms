// 题目描述：
//     定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
// 输入：
//     输入可能包含多个测试样例，输入以EOF结束。
//     对于每个测试案例，输入的第一行为一个整数n(1<=n<=1000000)， n代表将要输入的操作的步骤数。
//     接下来有n行，每行开始有一个字母Ci。
//     Ci=’s’时，接下有一个数字k，代表将k压入栈。
//     Ci=’o’时，弹出栈顶元素。
// 输出：
//     对应每个测试案例中的每个操作，
//     若栈不为空，输出相应的栈中最小元素。否则，输出NULL。
// 样例输入：
//     7
//     s 3
//     s 4
//     s 2
//     s 1
//     o
//     o
//     s 0
// 样例输出：
//     3
//     3
//     2
//     1
//     2
//     3
//     0

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, i, temp;
	char input;
	stack<int> main_stack, min_stack;
	while (cin >> n) {
		while (!main_stack.empty()) {
			main_stack.pop();
			min_stack.pop();
		}
		for (i = 0; i < n; ++i) {
			cin >> input;
			if (input == 'o') {
				temp = main_stack.top();
				min_stack.pop();
				main_stack.pop();
			} else if (input == 's') {
				cin >> temp;
				main_stack.push(temp);
				if (min_stack.size() == 0 || temp < min_stack.top())
					min_stack.push(temp);
				else
					min_stack.push(min_stack.top());
			}
			if (min_stack.empty()) {
				cout << "NULL" << endl;
			}
			else {
				cout << min_stack.top() << endl;
			}
		}

	}
	return 0;
}
