#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <time.h>

//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

using namespace std;

unsigned long long ModularExponentiation(int a, int b, int n);
bool Witness(int a, unsigned long long n);
bool MillerRabin(unsigned long long n, int s);
unsigned long long ModularMult(unsigned long long a, unsigned long long b, unsigned long long n);
void getBinary(bitset<64> *bit, unsigned long long a);
unsigned long long x[100];
const int s = 100;

#define N (sizeof(unsigned long long) * 8)
#define M (((unsigned long long)1) <<(N-1))

unsigned long long getBinaryLength(unsigned long long a) {

    unsigned long long i = sizeof(unsigned long long) * 8;
    while(i > 0) {
        if((a & M) != 0)
            break;
        a <<= 1;
        i --;
    }
    return i - 1;
}

/*
 * @brief 得到[i, j]的随机整数
 * @param[in] i:
 * @param[in] j:
 */
unsigned long long Randomi(unsigned long long i, unsigned long long j)
{
    return i + rand() % (j - i + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    int i;

    unsigned long long num;
    srand(time(NULL));
    for (i = 0; i < T; i++) {
        scanf("%llu", &num);
        if ((num % 2) == 0 && num != 2) {
            printf("No\n");
        }
        else if (num == 2) {
            printf("Yes\n");
        }
        else if (MillerRabin(num, s)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}

bool MillerRabin(unsigned long long n, int s)
{
    int j;
    unsigned long long a;
    for (j = 0; j < s; j++) {
        a = Randomi(1, n - 1);
        if (Witness(a, n)) {
            return false;
        }
    }
    return true;
}

unsigned long long ModularExponentiation(int a, unsigned long long b, unsigned long long n)
{
    unsigned long long d = 1;
    bitset<64> bit;
    getBinary(&bit, b);
    #ifdef DEBUG
    cout << bit << endl;
    #endif
    int i;
    for (i = 63; i >= 0; i--) {
        d = ModularMult(d, d, n);
        if (bit.test(i)) {
            //d = (d * a) % n;
            d = ModularMult(d, a, n);
        }
    }
    return d;
}

unsigned long long ModularMult(unsigned long long a, unsigned long long b, unsigned long long n)
{
    bitset<64> bit;
    getBinary(&bit, b);
    unsigned long long d = 0;
    int i;
    for (i = 63; i >= 0; i--) {
        d = ((d + d) % n);
        if (bit.test(i)) {
            d = (d + a) % n;
        }
    }
    return (d % n);
}


bool Witness(int a, unsigned long long n)
{
    int t = 0;
    int i;
    unsigned long long u = n - 1;
    while (u % 2 == 0) {
        u = u / 2;
        t++;
    }
    x[0] = ModularExponentiation(a, u, n);
    for (i = 1; i <= t; i++) {
        x[i] = ModularMult(x[i - 1], x[i - 1], n);
        if (x[i] == 1 && x[i - 1] != 1 && x[i - 1] != n - 1) {
            return true;
        }
    }
    if (x[t] != 1) return true;
    return false;
}
/*
 * 获得一个整数的二进制形式
 */
void getBinary(bitset<64> *bit, unsigned long long a)
{
    int i;
    for (i = 0; i < 64; i++) {
        if (a & 1) {
            (*bit)[i] = 1;
        }
        else {
            (*bit)[i] = 0;
        }
        a >>= 1;
    }
    #ifdef DEBUG
    //cout << bit << endl;
    #endif
}
