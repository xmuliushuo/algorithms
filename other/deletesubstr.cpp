// 删除字符串中所有给定的子串（40分）

// 问题描述： 
// 在给定字符串中查找所有特定子串并删除，如果没有找到相应子串，则不作任何操作。
// 要求实现函数： 
// int delete_sub_str(const char *str, const char *sub_str, char *result_str)
// 【输入】 str：输入的被操作字符串
//          sub_str：需要查找并删除的特定子字符串
// 【输出】 result_str：在str字符串中删除所有sub_str子字符串后的结果
// 注：
// I、   子串匹配只考虑最左匹配情况，即只需要从左到右进行字串匹配的情况。比如：
// 在字符串"abababab"中，采用最左匹配子串"aba",可以匹配2个"aba"字串。如果
// 匹配出从左到右位置2开始的"aba"，则不是最左匹配，且只能匹配出1个"aba"字串。
// II、  输入字符串不会超过100 Bytes，请不用考虑超长字符串的情况。

// 示例 
// 输入：str = "abcde123abcd123"
// sub_str = "123"
// 输出：result_str = "abcdeabcd"
// 返回：2

// 输入：str = "abcde123abcd123"
// sub_str = "1234"
// 输出：result_str = "abcde123abcd123"
// 返回：0

#include <iostream>
#include <cstring>

using namespace std;

int delete_sub_str(const char *str, const char *sub_str, char *result_str);

int main()
{
	int ret;
	char str[100];
	char sub_str[100];
	char result_str[100];
	cin >> str;
	cin >> sub_str;
	ret = delete_sub_str(str, sub_str, result_str);
	cout << result_str << endl;
	cout << ret << endl;
	return 0;
}

int delete_sub_str(const char *str, const char *sub_str, char *result_str)
{
	int str_length = strlen(str);
	int sub_str_length = strlen(sub_str);
	int ret = 0;
	if (sub_str_length > str_length) {
		result_str[0] = 0;
		return 0;
	}
	int i, j;
	for (i = 0, j = 0; i < str_length; ++i) {
		if (str[i] != sub_str[0]) {
			result_str[j++] = str[i];
		}
		else {
			int temp = i + 1;
			int k = 1;
			int match = 1;
			while (sub_str[k] != 0) {
				if (str[temp++] != sub_str[k++]) {
					match = 0;
					break;
				}
			}
			if (match) {
				i = temp - 1;
				++ret;
			}
			else {
				result_str[j++] = str[i];
			}
		}
	}
	result_str[j] = 0;
	return ret;
}