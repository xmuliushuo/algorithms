// Problem Statement
//     
// John has a sequence of integers. Brus is going to choose two different
// positions in John's sequence and swap the elements at those positions.
// (The two swapped elements may have the same value.) Return the number of
// different sequences Brus can obtain after he makes the swap.
// Definition
//     
// Class:
// TheSwapsDivTwo
// Method:
// find
// Parameters:
// vector <int>
// Returns:
// int
// Method signature:
// int find(vector <int> sequence)
// (be sure your method is public)
//     

// Constraints
// sequence will contain between 2 and 47 elements, inclusive.
// Each element of sequence will be between 1 and 47, inclusive.

// Examples
// 0)  
// {4, 7, 4}
// Returns: 3
// If Brus swaps elements 0 and 1 (0-based indices), the sequence will change
// to {7, 4, 4}. If he swaps elements 1 and 2 instead, the sequence will change
// to {4, 4, 7}. Finally, if the swaps elements 0 and 2, the sequence will
// remain {4, 7, 4}. These three outcomes are all distinct.
// 1)  
// {1, 47}
// Returns: 1
// Brus has to swap the only two elements, producing the sequence {47, 1}. Note
// that Brus has to make the swap, he cannot keep the original sequence.
// 2)  
// {9, 9, 9, 9}
// Returns: 1
// Regardless of which two elements Brus swaps, the resulting sequence will
// always be {9, 9, 9, 9}.
// 3)   
// {22, 16, 36, 35, 14, 9, 33, 6, 28, 12, 18, 14, 47, 46, 29, 22, 14, 17, 4,
// 15, 28, 6, 39, 24, 47, 37}
// Returns: 319

#include <vector>
#include <string>
#include <map>
//#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

class TheSwapsDivTwo
{
public:
	int find(vector<int> sequence)
	{
		m_count = sequence.size();
		for (vector<int>::iterator iter = sequence.begin(); iter != sequence.end(); ++iter) {
			++m_num[*iter];
		}
		int temp = m_count;
		int numCount = m_num.size();
		int result = 0;
		bool hasTwo = false;
		for (map<int, int>::iterator iter = m_num.begin(); iter != m_num.end(); ++iter) {
			temp -= (*iter).second;
			if ((*iter).second > 1) hasTwo = true;
			result += (*iter).second * temp;
		}
		if (hasTwo) ++result;
		return result;
	}
private:
	int m_count;
	map<int, int> m_num;
};
