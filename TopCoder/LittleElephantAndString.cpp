
// Problem Statement
//     
// Little Elephant from the Zoo of Lviv likes strings.

// You are given a string A and a string B of the same length. In one turn
// Little Elephant can choose any character of A and move it to the beginning of
// the string (i.e., before the first character of A). Return the minimal number
// of turns needed to transform A into B. If it's impossible, return -1 instead.

// Definition
//     
// Class: LittleElephantAndString
// Method: getNumber
// Parameters: string, string
// Returns: int
// Method signature: int getNumber(string A, string B)
// (be sure your method is public)
//     

// Constraints
// A will contain between 1 and 50 characters, inclusive.
// B will contain between 1 and 50 characters, inclusive.
// A and B will be of the same length.
// A and B will consist of uppercase letters ('A'-'Z') only.

// Examples

// 0)
//     
// "ABC"
// "CBA"
// Returns: 2

// The optimal solution is to make two turns. On the first turn, choose
// character 'B' and obtain string "BAC". On the second turn, choose character
// 'C' and obtain "CBA".

// 1)
//     
// "A"
// "B"
// Returns: -1
// In this case, it's impossible to transform A into B.

// 2)
//     
// "AAABBB"
// "BBBAAA"
// Returns: 3

// 3)
//     
// "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// "ZYXWVUTSRQPONMLKJIHGFEDCBA"
// Returns: 25

// 4)
//     
// "A"
// "A"
// Returns: 0

// 5)
//     
// "DCABA"
// "DACBA"
// Returns: 2

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