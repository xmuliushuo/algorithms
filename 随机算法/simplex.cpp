
#include <stdio.h>
void initializeSimplex();
// to get the index of the minimum b
//int minimum(double *array, int num);
// to get a positive index of c
int getPositiveIndexOfC();
int getMinimumIndexOfB(int e);
void simplex();
void pivot(int l, int e);

#define Max 100
double A[Max][Max];
double b[Max];
double c[Max];
int N[Max];
int B[Max];
int m, n;
int v = 0;
double ans[Max];
/*
int main()
{

	int i, j;
	printf("input m and n\n");
	scanf("%d %d", &m, &n);

	printf("input the matrix A(m * n)\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &A[i + n][j]);
		}
	}

	printf("input the vector b(m)\n");
	for (i = 0; i < m; i++) {
		scanf("%lf", &b[i + n]);
	}

	printf("input the vector c(n)\n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &c[i]);
	}
	
	simplex();
	return 0;
}
*/
void simplex()
{
	initializeSimplex();
	int e;
	int l;
	int i;
	//for (i = 0; i < n; i++) {
	//	printf("%lf ", c[i]);
	//}
	//printf("------\n");
	while (getPositiveIndexOfC() >= 0) {
		//printf("-------\n");
		e = getPositiveIndexOfC();
		l = getMinimumIndexOfB(e);
		if (l < 0) {
			printf("unbounded\n");
			return;
		}
		pivot(l, e);
	}

	for (i = 0; i < n; i++) {
		ans[i] = 0;
	}

	for (i = 0; i < m; i++) {
		if (B[i] < n) {
			ans[B[i]] = b[B[i]];
		}
	}

	printf("the answer :\n");
	for (i = 0; i < n; i++)
		printf("%lf ", ans[i]);
	printf("\n");
}

void pivot(int l, int e)
{
	int i, j;

	b[e] = b[l] / A[l][e];
	for (i = 0; i < n; i++) {
		if (N[i] != e) {
			A[e][N[i]] = A[l][N[i]] / A[l][e];
		}
	}
	A[e][l] = 1 / A[l][e];


	for (i = 0; i < m; i++) {
		if (B[i] != l) {
			b[B[i]] = b[B[i]] - A[B[i]][e] * b[e];
			for (j = 0; j < n; j++) {
				if (N[j] != e) {
					A[B[i]][N[j]] = A[B[i]][N[j]] - A[B[i]][e] * A[e][N[j]]; 
				}
			}
			A[B[i]][l] = -1 * A[B[i]][e] * A[e][l];
		}
	}

	v = v + c[e] * b[e];

	for(i = 0; i < n; i++) {
		if (N[i] != e) {
			c[N[i]] = c[N[i]] - c[e]* A[e][N[i]]; 
		}
	}

	c[l] = -1 * c[e] * A[e][l];

	for (i = 0; i < n; i++){
		if (N[i] == e) {
			N[i] = l;
		}
	}

	for (i = 0; i < m; i++) {
		if (B[i] == l) {
			B[i] = e;
		}
	}	
}

void initializeSimplex()
{
	int i;
	for (i = 0; i < n; i++) {
		N[i] = i;
	} 
	for (i = 0; i < m; i++) {
		B[i] = n + i;
	}
}

//int minimum(double *array, int num)
//{
//	double min = array[0];
//	int index = 0;
//	int i;
//	for (i = 1; i < num; i++) {
//		if (array[i] < min) {
//			min = array[i];
//			index = i;
//		}
//	}
//	return index;
//}

int getPositiveIndexOfC() {
	int i;
	for (i = 0; i < n; i++) {
		printf("c[N[i]] : %lf ", c[N[i]]);
		if (c[N[i]] > 0)
			return N[i];

	}
	return -1;
}

int getMinimumIndexOfB(int e) {
	int i;
	double delta = -1;
	double temp;
	int index = -1;
	for (i = 0; i < m; i++) {
		if (A[B[i]][e] > 0) {
			if (delta < 0) {
				delta = b[B[i]] / A[B[i]][e];
				index = i;
			}
			else if (b[B[i]] > 0) {
				temp = b[B[i]] / A[B[i]][e];
				if (temp < delta) {
					index = i;
					delta = temp;
				}
			}
		}
	}
	printf("%d\n", index);
	if (index == -1)
		return -1;
	else
		return B[index];
}
