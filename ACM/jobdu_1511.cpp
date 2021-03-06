// 题目描述：
//     输入一个链表，从尾到头打印链表每个节点的值。

// 输入：
//     每个输入文件仅包含一组测试样例。
//     每一组测试案例包含多行，每行一个大于0的整数，代表一个链表的节点。第一行是链表第一个节点的值，依次类推。当输入到-1时代表链表输入完毕。-1本身不属于链表。

// 输出：
//     对应每个测试案例，以从尾到头的顺序输出链表每个节点的值，每个值占一行。

// 样例输入：
//     1
//     2
//     3
//     4
//     5
//     -1

// 样例输出：
//     5
//     4
//     3
//     2
//     1

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;
stack<int> num_stack;
int main()
{
	int input;
	int output;
	scanf("%d", &input);
	while (input != -1) {
		num_stack.push(input);
		scanf("%d", &input);
	}
	while (!num_stack.empty()) {
		output = num_stack.top();
		printf("%d\n", output);
		num_stack.pop();
	}
	return 0;
}
