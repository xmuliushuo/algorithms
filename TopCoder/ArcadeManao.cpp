// Problem Statement
// You might remember the old computer arcade games. Here is one about Manao.  
// The game level is an NxM grid of equal cells. The bottom of some cells has 
// a platform at which Manao can stand. All the cells in the bottommost row contain a platform, 
// thus covering the whole ground of the level. The rows of the grid are numbered from 1 to N starting 
// from the top and the columns are numbered from 1 to M starting from the left. Exactly one cell contains
// a coin and Manao needs to obtain it.  Initially, Manao is standing on the ground, i.e., in the bottommost
// row. He can move between two horizontally adjacent cells if both contain a platform. Also, Manao has
// a ladder which he can use to climb. He can use the ladder to climb both up and down.
// If the ladder is L units long, Manao can climb between two cells (i1, j) and (i2, j) if both contain
// a platform and |i1-i2| <= L. Note that Manao carries the ladder along, so he can use it multiple times.
// You need to determine the minimum ladder length L which is sufficient to acquire the coin.
//  Take a look at the following picture. On this level, Manao will manage to get the coin with a ladder of length 2.   
// You are given a vector <int> level containing N elements. The j-th character in the i-th row of level is 'X' 
// if cell (i+1, j+1) contains a platform and '.' otherwise. You are also given ints coinRow and coinColumn.
// The coin which Manao seeks is located in cell (coinRow, coinColumn) and it is guaranteed that this cell contains a platform.
//  Return the minimum L such that ladder of length L is enough to get the coin. If Manao can perform the task without using
// the ladder, return 0.
// Definition
// Class:
// ArcadeManao
// Method:
// shortestLadder
// Parameters:
// vector <string>, int, int
// Returns:
// int
// Method signature:
// int shortestLadder(vector <string> level, int coinRow, int coinColumn)
// (be sure your method is public)

// Notes
// Manao is not allowed to fall. The only way in which he may change his vertical coordinate is by using the ladder.
// Constraints
// level will contain N elements, where N is between 1 and 50, inclusive.
// Each element of level will be M characters long, where M is between 1 and 50, inclusive.
// Each element of level will consist of '.' and 'X' characters only.
// The last element of level will be entirely filled with 'X'.
// coinRow will be between 1 and N, inclusive.
// coinColumn will be between 1 and M, inclusive.
// level[coinRow - 1][coinColumn - 1] will be 'X'.

// Examples
// 0)
// {"XXXX....",
//  "...X.XXX",
//  "XXX..X..",
//  "......X.",
//  "XXXXXXXX"}
// 2
// 4
// Returns: 2
// The example from the problem statement.

// 1)
// {"XXXX",
//  "...X",
//  "XXXX"}
// 1
// 1
// Returns: 1
// Manao can use the ladder to climb from the ground to cell (2, 4), then to cell (1, 4) and then he can walk right to the coin.

// 2)
// {"..X..",
//  ".X.X.",
//  "X...X",
//  ".X.X.",
//  "..X..",
//  "XXXXX"}
// 1
// 3
// Returns: 4
// With a ladder of length 4, Manao can first climb to cell (5, 3) and then right to (1, 3).

// 3)
// {"X"}
// 1
// 1
// Returns: 0
// Manao begins in the same cell as the coin.

// 4)
// {"XXXXXXXXXX",
//  "...X......",
//  "XXX.......",
//  "X.....XXXX",
//  "..XXXXX..X",
//  ".........X",
//  ".........X",
//  "XXXXXXXXXX"}
// 1
// 1
// Returns: 2

// 思路：利用图的深度优先搜索或者广度优先搜索

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;



class ArcadeManao
{
public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn);
private:
	void dfs(int x, int y);
	int m_row;
	int m_column;
	int G[51][51];
	int ladder;
	vector<string> m_level;
};

void ArcadeManao::dfs(int x, int y)
{
	//cout << x << ", " << y << endl;
	G[x][y] = 1;
	int i;
	int low, high;
	if (x - ladder < 1) low = 1;
	else low = x - ladder;
	if (x + ladder > m_row) high = m_row;
	else high = x + ladder;
	//cout << "m_column:" << m_column << endl;
	//cout << "low:" << low << endl;
	//cout << "high:" << high << endl;
	for (i = low; i <= high; ++i) {
		if (G[i][y] == 0 && m_level[i - 1][y - 1] == 'X') {
			dfs(i, y);
		}
		G[i][y] = 1;
	}
	if (y > 1 && G[x][y - 1] == 0 && m_level[x - 1][y - 2] == 'X')
		dfs(x, y - 1);
	if (y < m_column && G[x][y + 1] == 0 && m_level[x - 1][y] == 'X')
		dfs(x, y + 1);
}

int ArcadeManao::shortestLadder(vector <string> level, int coinRow, int coinColumn)
{
	m_level = level;
	m_row = level.size();
	m_column = level[0].size();
	int i, j;
	for (i = 1; i <= m_row; ++i) {
		for (j = 1; j <= m_column; ++j) {
			G[i][j] = 0;
		}
	}
	ladder = -1;
	while (G[m_row - coinRow + 1][coinColumn] != 1) {
		ladder++;
		for (i = 1; i <= m_row; ++i) {
			for (j = 1; j <= m_column; ++j) {
				G[i][j] = 0;
			}
		}
		dfs(1, 1);
		
		//cout << ladder << endl;
	}
	return ladder;
}

int main()
{
	vector<string> level;
	//level.push_back("XXXXXXXX");
	//level.push_back("......X.");
	//level.push_back("XXX..X..");
	//level.push_back("...X.XXX");
	//level.push_back("XXXX....");
	level.push_back("XXXXX");
	level.push_back("..X..");
	level.push_back(".X.X.");
	level.push_back("X...X");
	level.push_back(".X.X.");
	level.push_back("..X..");
	ArcadeManao temp;
	cout << temp.shortestLadder(level, 1, 3) << endl;
	system("pause");
	return 0;
}