﻿
// Problem Statement
// Manao is conducting an experiment to measure the humidity level of some spongy material. 
// The experiment is conducted in a closed room which is observed from a side, so we will consider it in two dimensions. 
// The room is N centimeters wide. There are N drop counters built in the ceiling of the room. 
// Drop counter 0 is attached 0.5 centimeters from the left end of the room,
// and each next one is attached 1 centimeter to the right of the previous one. 
// The i-th (0-based index) drop counter drips intensity[i] drops per minute. 
// There are also M sponges in the room. The i-th (0-based) sponge is horizontally 
// attached (i+1) centimeters below the ceiling and its left end is leftEnd[i] centimeters apart from the left wall of the room.
// All sponges are exactly L centimeters long and their thickness is negligible. Each sponge will totally absorb every drop that drips at it.    You are given a vector <int> intensity containing exactly N elements, a vector <int> leftEnd containing exactly M elements and a int L. You have to model the experiment that Manao is conducting to compute the amount of drops that each sponge will absorb per minute. Return a vector <int> of length M, where i-th element will be the number of drops absorbed by the i-th sponge.

// Definition
// Class:
// TheExperimentDiv2
// Method:
// determineHumidity
// Parameters:
// vector <int>, int, vector <int>
// Returns:
// vector <int>
// Method signature:
// vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd)
// (be sure your method is public)
//     

// Constraints
// intensity will contain N elements, where N is between 1 and 50, inclusive.
// Each element of intensity will be between 1 and 1000, inclusive.
// L will be between 1 and N, inclusive.
// leftEnd will contain M elements, where M is between 1 and 50, inclusive.
// Each element of leftEnd will be between 0 and N - L, inclusive.

// Examples
// 0)
// {3, 4, 1, 1, 5, 6}
// 3
// {3, 1, 0}
// Returns: {12, 5, 3 }
// This is the example shown in the problem statement. The drops from counters 3, 4, 5 are absorbed by sponge 0, the drops from counters 1 and 2 are absorbed by sponge 1 and the drops from counter 0 are absorbed by sponge 2.

// 1)
// {5, 5}
// 2
// {0, 0}
// Returns: {10, 0 }
// There are two sponges, one right below another. The first sponge absorbs all drops and the second receives none.

// 2)
// {92, 11, 1000, 14, 3}
// 2
// {0, 3}
// Returns: {103, 17 }
// Note that some drops may fall down on the floor.

// 3)
// {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13}
// 4
// {1, 7, 4, 5, 8, 0}
// Returns: {39, 14, 110, 0, 13, 2 }


#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;



class TheExperimentDiv2
{
public:
	vector <int> determineHumidity(vector<int> intensity, int L, vector <int> leftEnd);
};

vector <int> TheExperimentDiv2::determineHumidity(vector <int> intensity, int L, vector <int> leftEnd)
{
	vector<int> result;
	int start = leftEnd[0];
	int end = L;
	int count = 0;
	for (vector<int>::iterator iter = leftEnd.begin(); iter != leftEnd.end(); ++iter) {
		end = *iter + L;
		start = *iter;
		result.push_back(0);
		for (int i = start; i < end; ++i) {
			result[count] += intensity[i];
			intensity[i] = 0;
		}
		count++;
	}
	return result;
}

//int main()
//{
//	return 0;
//}