
// Problem Statement

// Crow Keith is looking at the goose cage in the zoo. The bottom of the cage is
// divided into a grid of square cells. There are some birds sitting on those
// cells (with at most one bird per cell). Some of them are geese and all the
// others are ducks. Keith wants to know which birds are geese. He knows the
// following facts about them: There is at least one goose in the cage. Each
// bird within Manhattan distance dist of any goose is also a goose. You are
// given a vector <string> field and the int dist. The array field describes the
// bottom of the cage. Each character of each element of field describes one of
// the cells. The meaning of individual characters follows. The character 'v'
// represents a cell that contains a bird. The character '.' represents an empty
// cell. Return the number of possible sets of geese in the cage, modulo
// 1,000,000,007. Note that for some of the test cases there can be no possible
// sets of geese.

// Definition
// Class:
// GooseInZooDivTwo
// Method:
// count
// Parameters:
// vector <string>, int
// Returns:
// int
// Method signature:
// int count(vector <string> field, int dist)
// (be sure your method is public)
//     

// Notes
// The Manhattan distance between cells (a,b) and (c,d) is |a-c| + |b-d|, where
// || denotes absolute value. In words, the Manhattan distance is the smallest
// number of steps needed to get from one cell to the other, given that in each
// step you can move to a cell that shares a side with your current cell.

// Constraints
// field will contain between 1 and 50 elements, inclusive.
// Each element of field will contain between 1 and 50 characters, inclusive.
// Each element of field will contain the same number of characters.
// Each character of each element of field will be 'v' or '.'.
// dist will be between 0 and 100, inclusive.

// Examples
// 0)
// {"vvv"}
// 0
// Returns: 7
// There are seven possible sets of positions of geese: "ddg", "dgd", "dgg", "gdd", "gdg", "ggd", "ggg" ('g' are geese and 'd' are ducks).

// 1)
// {"."}
// 100
// Returns: 0
// The number of geese must be positive, but there are no birds in the cage.

// 2)  
// {"vvv"}
// 1
// Returns: 1

// 3) 
// {"v.v..................v............................"
// ,".v......v..................v.....................v"
// ,"..v.....v....v.........v...............v......v..."
// ,".........vvv...vv.v.........v.v..................v"
// ,".....v..........v......v..v...v.......v..........."
// ,"...................vv...............v.v..v.v..v..."
// ,".v.vv.................v..............v............"
// ,"..vv.......v...vv.v............vv.....v.....v....."
// ,"....v..........v....v........v.......v.v.v........"
// ,".v.......v.............v.v..........vv......v....."
// ,"....v.v.......v........v.....v.................v.."
// ,"....v..v..v.v..............v.v.v....v..........v.."
// ,"..........v...v...................v..............v"
// ,"..v........v..........................v....v..v..."
// ,"....................v..v.........vv........v......"
// ,"..v......v...............................v.v......"
// ,"..v.v..............v........v...............vv.vv."
// ,"...vv......v...............v.v..............v....."
// ,"............................v..v.................v"
// ,".v.............v.......v.........................."
// ,"......v...v........................v.............."
// ,".........v.....v..............vv.................."
// ,"................v..v..v.........v....v.......v...."
// ,"........v.....v.............v......v.v............"
// ,"...........v....................v.v....v.v.v...v.."
// ,"...........v......................v...v..........."
// ,"..........vv...........v.v.....................v.."
// ,".....................v......v............v...v...."
// ,".....vv..........................vv.v.....v.v....."
// ,".vv.......v...............v.......v..v.....v......"
// ,"............v................v..........v....v...."
// ,"................vv...v............................"
// ,"................v...........v........v...v....v..."
// ,"..v...v...v.............v...v........v....v..v...."
// ,"......v..v.......v........v..v....vv.............."
// ,"...........v..........v........v.v................"
// ,"v.v......v................v....................v.."
// ,".v........v................................v......"
// ,"............................v...v.......v........."
// ,"........................vv.v..............v...vv.."
// ,".......................vv........v.............v.."
// ,"...v.............v.........................v......"
// ,"....v......vv...........................v........."
// ,"....vv....v................v...vv..............v.."
// ,".................................................."
// ,"vv........v...v..v.....v..v..................v...."
// ,".........v..............v.vv.v.............v......"
// ,".......v.....v......v...............v............."
// ,"..v..................v................v....v......"
// ,".....v.....v.....................v.v......v......."}
// 3
// Returns: 797922654

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <sstream>
#include <set>
#include <bitset>

using namespace std;

class GooseInZooDivTwo
{
public:
    stack<int> x;
    stack<int> y;
    int row;
    int column;
    vector <string> mfield;
    int mdist;
    int abs(int a) {
        if (a < 0) return -a;
        return a;
    }
    void f(int i, int j) {
        for (int k = 0; k < row; ++k) {
            for (int t = 0; t < column; ++t) {
                if (abs(k - i) + abs(t - j) <= mdist && mfield[k][t] == 'v') {
                    x.push(k);
                    y.push(t);
                    mfield[k][t] = '.';
                }
            }
        }
    }
    int count(vector <string> field, int dist)
    {
        mdist = dist;
        mfield = field;
        row = field.size();
        column = field[0].size();
        int count = 0;
        int result = 1;
        int t1, t2;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (mfield[i][j] == 'v'){
                    count++;
                    mfield[i][j] = '.';
                    f(i, j);
                    while (!x.empty()) {
                        t1 = x.top();
                        t2 = y.top();
                        x.pop();
                        y.pop();
                        f(t1, t2);
                    }
                }
            }
        }
        for (int i = 0; i < count; i++) {
            result *= 2;
            result = result % 1000000007;
        }
        --result;
        return result;
    }

private:
};