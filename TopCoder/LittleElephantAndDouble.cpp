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

class LittleElephantAndDouble
{
public:
	string getAnswer(vector <int> A)
	{
		for (int i = 0; i < A.size(); ++i) {
			A[i] = handle(A[i]);
			cout << A[i] << endl;
		}
		bool result = true;
		for (int i = 1; i < A.size(); ++i) {
			if (A[i - 1] != A[i]) { 
				result = false;
				break;
			}
		}
		if (result) {
			return "YES";
		}
		else {
			return "NO";
		}
	}
private:
	int handle(int num)
	{
		while ((num % 2) == 0) {
			num /= 2;
		}
		return num;
	}
};

int main()
{
	return 0;
}