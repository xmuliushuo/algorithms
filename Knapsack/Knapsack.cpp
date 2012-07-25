
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

using namespace std;

int size; // 数据规模
int *value; // 物品价值
int *weight; // 物品重量
int contain; // 背包容量
int *result;

int isSA = 0;
int isGreedy = 0;
int isDPW = 0;

int t0 = 100; // 初始温度
double beta = 0.01; // 停止准则
double alpha = 0.9; // 退火系数
int L;

int best = -1;

int totalWeight = 0;
int totalValue = 0;

void getInitResult();
int Randomi(int i, int j);
void SA();
double Randomf(double a, double b);
void createData();
int compare(const void *a, const void *b);
void greedy();
void backtrack(int i);
void DPW();

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int isCreateData = 0;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			if (i + 1 >= argc) {
				printf("usage\n");
				return 0;
			}
			else {
				size = atoi(argv[i + 1]);
				isCreateData = 1;
			}
		}
		else if ((strcmp(argv[i], "-s")) == 0) {
			isSA = 1;
		}
		else if (strcmp(argv[i], "-g") == 0){
			isGreedy = 1;
		}
		else if (strcmp(argv[i], "-p") == 0) {
            isDPW = 1;
		}
	}
	if (isCreateData == 1) {
		//生成测试数据
		createData();
	}
	else {
		// 输入数据
		scanf("%d", &size);
		value = (int *)malloc(sizeof(int) * size);
		weight = (int *)malloc(sizeof(int) * size);
		result = (int *)malloc(sizeof(int) * size);
		int temptotalWeight = 0;
		for (int i = 0; i < size; i++)
		{
			result[i] = 0;
			scanf("%d %d", value + i, weight + i);
			temptotalWeight += *(weight + i);
		}
		contain = temptotalWeight / 2;
		int start = clock();
		if (isSA == 1) {
			SA();
		}
		else if (isGreedy == 1) {
			greedy();
			best = totalValue;
		}
		else if (isDPW == 1) {
            DPW();
		}
		else{
			backtrack(0);
		}
		int end = clock();
		printf("total value: %d\n", best);
		printf("total time: %lf s\n", ((double)(end - start)) / CLOCKS_PER_SEC);
	}
	return 0;
}

void getInitResult()
{
	int temp;
	while (totalWeight <= contain) {
		temp = Randomi(0, size);
		if (result[temp] == 0) {
			result[temp] = 1;
			totalWeight += weight[temp];
			totalValue += value[temp];
		}
	}
	result[temp] = 0;
	totalWeight -= weight[temp];
	totalValue -= value[temp];
	return;
}

int Randomi(int i, int j)
{
    return i + rand() % (j - i + 1);
}

double Randomf(double a, double b)
{
    double temp = (double)rand() / RAND_MAX;
    return a + (b - a) * temp;
}

void SA()
{
	double t = (double)t0;
	getInitResult();
	int a, b;
	int temptotalWeight, temptotalValue;
	int *tempresult = (int *)malloc(sizeof(int) * size);
	L = 10 * size;
	while (t > beta) {
		for (int i = 0; i < L; i++) {
			temptotalValue = totalValue;
			temptotalWeight = totalWeight;
			memcpy(tempresult, result, sizeof(int) * size);

			// 产生邻域
			a = Randomi(0, size);
			b = Randomi(0, size);
			while (b == a) {
				b = Randomi(0, size);
			}
			if ((tempresult[a] == 0) && (tempresult[b] == 1)) {
				tempresult[b] = 0;
				temptotalValue -= value[b];
				temptotalWeight -= weight[b];
				tempresult[a] = 1;
				temptotalValue += value[a];
				temptotalWeight += weight[a];
			}
			else if((tempresult[a] == 0) && (tempresult[b] == 0)) {
				tempresult[a] = 1;
				temptotalValue += value[a];
				temptotalWeight += weight[a];
			}
			else if ((tempresult[a] == 1) && (tempresult[b] == 1)) {
				tempresult[a] = 0;
				temptotalValue -= value[a];
				temptotalWeight -= weight[a];
			}
			else if ((tempresult[a] == 1) && (tempresult[b] == 0)) {
				tempresult[a] = 0;
				temptotalValue -= value[a];
				temptotalWeight -= weight[a];
				temptotalWeight += weight[b];
				temptotalValue += value[b];
				tempresult[b] = 1;
			}

			int delta = temptotalValue - totalValue;
			if ((delta > 0) && (temptotalWeight <= contain))
			{
				memcpy(result, tempresult, sizeof(int) * size);
				totalValue = temptotalValue;
				totalWeight = temptotalWeight;
			}
			else if (temptotalWeight <= contain)
			{
				//以一定概率接受解
				if (Randomf(0,1) < exp(delta / t)) {
					memcpy(result, tempresult, sizeof(int) * size);
					totalValue = temptotalValue;
					totalWeight = temptotalWeight;
				}
			}
			if (((temptotalValue > best) || (best == -1)) && (temptotalWeight <= contain)) {
					best = temptotalValue;
			}
		}
		t *= alpha;
	}
	free(tempresult);
	return;
}

void createData()
{
	printf("%d\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d %d\n", Randomi(0, 100), Randomi(0, 1000));
	}
	return;
}

struct temp {
    int index;
    double order;
};

void greedy()
{
	temp *s_order = (temp *)malloc(sizeof(temp) * size);

	for (int i = 0; i < size; i++) {
		s_order[i].index = i;
		s_order[i].order = ((double)value[i]) / weight[i];
	}
	qsort(&s_order[0], size, sizeof(s_order[0]), compare);
	for (int i = 0; i < size; i++) {
		if ((totalWeight + weight[s_order[i].index]) <= contain) {
			totalWeight += weight[s_order[i].index];
			totalValue += value[s_order[i].index];
			result[s_order[i].index] = 1;
		}
	}
	free(s_order);
}

int compare(const void *a, const void *b)
{
	if (((*(temp *)b).order - (*(temp *)a).order) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}


void backtrack(int i)
{
	if (i > size) {
		if ((totalValue > best) || (best == -1)) {
			best = totalValue;
		}
	}
	else {
		if ((totalWeight + weight[i]) <= contain) {
			totalWeight += weight[i];
			totalValue += value[i];
			result[i] = 1;
			backtrack(i + 1);
			totalValue -= value[i];
			totalWeight -= weight[i];
			result[i] = 0;
		}
		backtrack(i + 1);
	}

}

void DPW()
{
    int i, j;
    //int W = 0;
    int **V = new int *[size];
    for (i = 0; i < size; i++) {
        V[i] = new int[contain + 1];
    }
    for (i = 0; i < weight[0]; i++) {
        V[0][i] = 0;
    }
    for (i = weight[0]; i <= contain; i++) {
        V[0][i] = value[0];
    }
    for (i = 1; i < size; i++) {
        for (j = 0; j <= contain; j++) {
            if (weight[i] > j) {
                V[i][j] = V[i - 1][j];
            }
            else {
                if (V[i - 1][j] > (V[i - 1][j - weight[i]] + value[i])) {
                    V[i][j] = V[i - 1][j];
                }
                else {
                    V[i][j] = V[i - 1][j - weight[i]] + value[i];
                }
            }
        }
    }
    best = V[size - 1][contain];
}
