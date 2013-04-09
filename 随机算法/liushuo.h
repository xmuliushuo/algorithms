#ifndef LIUSHUO
#define LIUSHUO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ABS(x) (x) > 0 ? (x) : -(x)

void RandomSampling(int *set, int n, int m, int *sample);
double Randomf(double a, double b);
int Randomi(int i, int j);
void swap(int *a, int *b);
int RandomizedPartition(int *a, int p, int r);
void RandomizedQuickSort(int *a, int p, int r);
int RandomizedSelect(int *a, int p, int r, int i);
bool QueensLVB(int *x, int stopLV, int *node);
int GCD(int a, int b);
void PollardRho(int n);

#endif
