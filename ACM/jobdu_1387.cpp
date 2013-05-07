#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    int n, i;
    long long f[71];
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= 70; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (cin >> n) {
        cout << f[n] << endl;
    }
    return 0;
}