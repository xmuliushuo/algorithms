#include "liushuo.h"

// 交换两个数的值
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

double Randomf(double a, double b)
{
    double temp = (double)rand() / RAND_MAX;
    return a + (b - a) * temp;
}

int Randomi(int i, int j)
{
    return i + rand() % (j - i + 1);
}

/*
 * @brief 用于计算两个整数的最大公约数
 * @param[in] a: 整数a
 * @param[in] b: 整数b
 * @return a, b的最大公约数
 */
int GCD(int a, int b)
{
    while( 1 )
    {
        a = a % b;
		if (a == 0)
			return b;
		b = b % a;
        if(b == 0)
			return a;
    }
}
