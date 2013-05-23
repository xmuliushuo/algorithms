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

class PrimalUnlicensedCreatures
{
public:
    int maxWins(int initialLevel, vector <int> grezPower)
    {
        sort(grezPower.begin(), grezPower.end());
        int count = 0;
        for (int i = 0; i < grezPower.size(); ++i) {
            if (initialLevel > grezPower[i]) {
                initialLevel += grezPower[i] / 2;
                ++count;
            }
            else break;
        }
        return count;
    }
private:
};