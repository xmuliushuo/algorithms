// 1463.小海的困惑
// Time Limit: 1000 MS         Memory Limit: 65536 K 
// Description
// 小海的搜索引擎公司开始有起色了。每天的查询次数很多，但是小海需要找到查询
// 次数最多的，他准备对该查询投放广告。但是他需要在大量的查询中找到该关键字。请你帮帮他吧
// Input
// 输入的第一行为一个整数M(0<=M<=10000)，表示查询的单词量。接下来为M个单词，
// 每个单词用空格隔开，并且每个单词的长度不超过20。单词只由大小写字母构成，但是大小写不敏感。
// Output
// 输出查询次数最多的单词(输出的单词一律为小写)以及查询的次数，中间用一个空格隔开。
// 如果有多个单词满足条件，请输出字典序最小的单词。
// Sample Input
// 5
// Ab ab c aB d
// Sample Output
// ab 3


#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	map<string, int> wordmap;
	cin >> n;
	string temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		for (string::iterator iter = temp.begin(); 
			iter != temp.end(); ++iter) {
			if (*iter >= 'A' && *iter <= 'Z') *iter = *iter -'A' + 'a';
		}
		++wordmap[temp];
	}
	int max = 0;
	string result = wordmap.begin()->first;
	for (map<string, int>::iterator iter = wordmap.begin(); 
		iter != wordmap.end(); ++iter) {
		if (max < (*iter).second) {
			result = (*iter).first;
			max = (*iter).second;
		}
		else if(max == (*iter).second && (*iter).first < result) {
			result = (*iter).first;
		}
	}
	cout << result << " " << max << endl;
	return 0;
}