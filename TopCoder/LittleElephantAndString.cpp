#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <sstream>
#include <set>

using namespace std;

class LittleElephantAndString
{
public:
	int getNumber(string A, string B)
	{
		map<char, int> count;
		for (int i = 0; i < A.size(); ++i) {
			count[A[i]]++;
		}
		for (int i = 0; i < B.size(); ++i) {
			count[B[i]]--;
			if (count[B[i]] < 0) return -1;
		}
		int i = B.size() - 1;
		int j = A.size() - 1;
		int length = 0;
		while (true) {
			while (A[j] != B[i]) {
				--j;
				if (j < 0) break;
			}
			if (j < 0) break;
			--i;
			--j;
			++length;
			if (j < 0) break;
		}
		int result = A.size() - length;
		return result;
	}
private:

};

int main()
{
	return 0;
}