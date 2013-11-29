#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class ErasingCharacters
{
public:
	string simulate(string s)
	{
		char result[51];
		int index = 0;
		int find = 0;
		// if (s.size() > 1) {
		for (int i = 0; i < s.size(); ++i) {
			if ((i < s.size() - 1) && (s[i] == s[i + 1]) && !find) {
				find = 1;
				i++;
			}
			else {
				result[index++] = s[i];
			}
		}
		// }
		
		result[index] = 0;
		// cout << result << endl;
		string r(result);
		if (find)
			r = simulate(r);
		return r;
	}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
