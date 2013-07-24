// 题目描述：
//     请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

// 输入：
//     每个输入文件仅包含一组测试样例。
//     对于每组测试案例，输入一行代表要处理的字符串。

// 输出：
//     对应每个测试案例，出经过处理后的字符串。

// 样例输入：
//     We Are Happy

// 样例输出：
//     We%20Are%20Happy

#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

string input;
char *output;

int main()
{
	getline(cin, input);
	int length = input.size();
	int i = 0;
	int blank_num = 0;
	for (i = 0; i < length; ++i) {
		if (input[i] == ' ') ++blank_num; 
	}
	length += 2 * blank_num + 1;
	output = (char *)malloc(length);
	int j = 0;
	for (i = 0; i < input.size(); ++i) {
		if (input[i] != ' ') output[j++] = input[i];
		else {
			output[j++] = '%';
			output[j++] = '2';
			output[j++] = '0';
		}
	}
	output[j] = 0;
	printf("%s\n", output);
	return 0;
}
