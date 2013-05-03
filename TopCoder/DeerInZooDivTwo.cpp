
// Problem Statement      
// Brus and Gogo came to the zoo today. It's the season
// when deer shed their antlers. There are N deer in the zoo. Initially, each
// deer had exactly two antlers, but since then some deer may have lost one or
// both antlers. (Now there may be some deer with two antlers, some with one,
// and some with no antlers at all.)  Brus and Gogo went through the deer
// enclosure and they collected all the antlers already lost by the deer. The
// deer have lost exactly K antlers in total. Brus and Gogo are now trying to
// calculate how many deer have not lost any antlers yet.  Return a vector
// <int> with exactly two elements {x,y}, where x is the smallest possible
// number of deer that still have two antlers, and y is the largest possible
// number of those deer.

// Definition
//     
// Class:
// DeerInZooDivTwo
// Method:
// getminmax
// Parameters:
// int, int
// Returns:
// vector <int>
// Method signature:
// vector <int> getminmax(int N, int K)
// (be sure your method is public)
//     

// Constraints
// N will be between 1 and 1000, inclusive.
// K will be between 0 and 2N, inclusive.

// Examples
// 0)
// 3
// 2
// Returns: {1, 2 }
// There are two possibilities: Either the K=2 antlers come from two different
// deer, or they come from the same deer. In the first case, there is 1 deer
// with two antlers (and two other with one antler each), in the second case
// there are 2 deer with two antlers each (and one deer with none).

// 1)
// 3
// 3
// Returns: {0, 1 }

// 2)
// 10
// 0
// Returns: {10, 10 }
// All deer still have 2 horns.

// 3)
// 654
// 321
// Returns: {333, 493 }

// 4) 
// 100
// 193
// Returns: {0, 3 }


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

class DeerInZooDivTwo
{
public:
    vector <int> getminmax(int N, int K)
    {
        int min, max;
        min = N - K;
        if (min < 0) min = 0;
        max = N - K / 2;
        if (K % 2 != 0) --max;
        vector<int> result;
        result.push_back(min);
        result.push_back(max);
        return result;
    }

private:
};