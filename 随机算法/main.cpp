/*
 * 主程序文件
 * author: 刘硕
 * xmuliushuo@gmail.com
 * xmuliushuo.com
 */

#include "liushuo.h"

void testRandomSampling();
void testRandomizedSelect();
void testRandomizedQuickSort();
void testQueensLVB();
void testPollardRho();

int main()
{
    printf("1.Random Sampling\n");
    printf("2.Randomized Quick Sort\n");
    printf("3.Randomized Select\n");
    printf("4.8 Queens\n");
    printf("5.PollardRho\n");
    printf("Please input the number of the algorithm\n(eg. \"1\")\n");
    int num;
    scanf("%d", &num);
    srand(time(NULL));
    switch(num) {
        case 1:
            testRandomSampling();
            break;
        case 2:
        	testRandomizedQuickSort();
        	break;
        case 3:
        	testRandomizedSelect();
        	break;
        case 4:
            testQueensLVB();
            break;
        case 5:
            testPollardRho();
            break;
        default:
            printf("error! Please input the number of the algorithm\n");
    }
    return 0;
}

/*
 * @brief 用于测试随机取样算法
 */
void testRandomSampling()
{
    int n, m;
    printf("RandomSamping\n");
    printf("set S = {0, 1, 2, 3, ... , n}\n");
    printf("now please input the number n: \n(eg. \"10\")\n");
    scanf("%d", &n);
    printf("now please input the number m: \n(eg. \"5\")\n");
    scanf("%d", &m);
    int *S = new int[n];
    int *a = new int[m];
    RandomSampling(S, n, m, a);
    printf("result:\n");
    for (int i = 0; i < m; i ++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    delete[] S;
    delete[] a;
}

/*
 * @brief 用于测试随机选择算法
 */
void testRandomizedSelect()
{
	printf("input the size of the array:\n(eg. \"5\")\n");
	int n;
	scanf("%d", &n);
	int *a = new int[n];
	int i;
	printf("input the number i:\n(eg. \"3\")\n");
	scanf("%d", &i);
	printf("input the array:\n(eg. \"1 2 5 3 4\")\n");
	for (int j = 0; j < n; j++) {
		scanf("%d", &a[j]);
	}
	int result = RandomizedSelect(a, 0, n - 1, i);
	printf("result:%d\n", result);
	delete[] a;
}

/*
 * @brief 用于测试随机快排算法
 */
void testRandomizedQuickSort()
{
	printf("input the size of the array:\n(eg. \"10\")\n");
	int n;
	scanf("%d", &n);
	printf("input the array:\n(eg. \"9 8 7 6 5 4 3 2 1 0\")\n");
	int *a = new int[n];
	for (int j = 0; j < n; j++) {
		scanf("%d", &a[j]);
	}
	RandomizedQuickSort(a, 0, n - 1);
	printf("result:\n");
    for (int i = 0; i < n; i++) {
    	printf("%d ", a[i]);
    }
    printf("\n");
	delete[] a;
}

/*
 * @brief 用于测试八皇后
 */
void testQueensLVB()
{
    int x[9];
    int i;
    const int Num = 10000;
    int count;
    int sum_s = 0;
    int node;
    double s = 0;
    double f = 0;
    int sum_f = 0;
    double t = 0;
    double p;
    int stopLV;
    printf("stopLV\tp\ts\tf\tt\n");
    for (stopLV = 0; stopLV < 9; stopLV++) {
        count = 0;
        sum_s = 0;
        sum_f = 0;
        for (i = 0; i < Num; i++) {
            node = 0;
            if (QueensLVB(x, stopLV, &node) == true) {
                count++;
                sum_s += node;
            }
            else {
                sum_f += node;
            }
        }
        p = (double) count / Num;
        s = (double) sum_s / count;
        if ((Num - count) != 0) {
            f = (double) sum_f / (Num - count);
        }
        else {
            f = 0.0;
        }
        t = s + (1- p) / p * f;
        printf("%d\t%.4lf\t%.2lf\t%.2lf\t%.2lf\n", stopLV, p, s, f, t);
    }
}

/*
 * @brief 用于测试大数因子分解算法
 */
void testPollardRho()
{
    printf("input num n\n");
    int n;
    scanf("%d", &n);
    PollardRho(n);
}
