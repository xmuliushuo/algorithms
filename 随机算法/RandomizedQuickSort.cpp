/*
 * RandomizedQuickSort.c
 * 随机快速排序算法
 * 刘硕
 * xmuliushuo@gmail.com
 * xmuliushuo.com
 */
 
#include "liushuo.h"

int Partition(int *a, int p, int r);

int Partition(int *a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(a + i, a + j);
        }
    }
    swap(a + i + 1, a + r);
    return i + 1;
}

void RandomizedQuickSort(int *a, int p, int r)
{
	int q;
	if (p < r) {
		q = RandomizedPartition(a, p, r);
		RandomizedQuickSort(a, p, q - 1);
		RandomizedQuickSort(a, q + 1, r);
	}
}

int RandomizedPartition(int *a, int p, int r)
{
	int i = Randomi(p, r);
	swap(a + r, a + i);
	return Partition(a, p, r);
}
