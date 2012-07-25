#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Randomi(int i, int j)
{
    return i + rand() % (j - i + 1);
}

int G[20][20];
int R[20][20];
int result[20];
int n;
int flag[20];
int best = 2147483647;
int Rcopy[20][20];
int RandomV()
{
    int list[20];
    int i;
    int count = 0;
    for (i = 0; i < n; i++) {
        if (result[i] == 0) {
            list[count] = i;
            count++;
        }
    }
    return list[Randomi(0, count - 1)];
}
int main()
{
    //int n;
    srand(time(NULL));
    int i, j, k;
    int v;
    int count;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    if (n == 1) {
        printf("0\n");
        printf("0\n");
        return 0;
    }
    if (n == 2) {
        printf("%d\n", G[0][1] * 2);
        printf("0 1\n");
        return 0;
    }
    for (k = 0; k < 10; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                R[i][j] = 0;
            }
            result[i] = 0;
            //flag[i] = 0;
        }
        v = RandomV();
        result[v] = 1;
        v = RandomV();
        result[v] = 1;
        v = RandomV();
        result[v] = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((result[i] == 1) && (result[j] == 1)) {
                    R[i][j] = G[i][j];
                    R[j][i] = G[j][i];
                }
            }
        }

        count = 3;
        int min;
        int temp;
        int a, b;
        while (count < n) {
            min = 2147483647;
            temp = 0;
            v = RandomV();
            for (i = 0; i < n; i++) {
                for (j = i; j < n; j++) {
                    if (R[i][j] > 0) {
                        temp = G[i][v] + G[v][j] - R[i][j];
                        if (min > temp) {
                            min = temp;
                            a = i;
                            b = j;
                        }
                    }
                }
            }
            result[v] = 1;
            R[a][b] = 0;
            R[b][a] = 0;
            R[a][v] = G[a][v];
            R[v][a] = G[a][v];
            R[b][v] = G[b][v];
            R[v][b] = G[v][b];
            count++;
        }
        int sum = 0;

        for (i = 0; i < n; i++) {
            for (j = i; j < n; j++) {
                sum += R[i][j];
            }
        }

        if (best > sum) {
            best = sum;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    Rcopy[i][j] = R[i][j];
                }
            }
        }
    }
    printf("%d\n", best);
    printf("0 ");
    flag[0] = 1;
    count = 2;
    for (i = 0; i < n; i++) {
        if (Rcopy[0][i] > 0) {
            printf("%d ", i);
            flag[i] = 1;
            break;
        }
    }

    while (count < n) {
        for (j = 0; j < n; j++) {
            if ((Rcopy[i][j] > 0) && flag[j] == 0) {
                printf("%d ", j);
                i = j;
                flag[j] = 1;
                count++;
                break;
            }
        }
    }

    return 0;
}
