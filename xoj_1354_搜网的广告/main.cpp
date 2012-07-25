#include <stdio.h>
#include <stdlib.h>

int budget[1001];
int remain[1001];
int bid[1001][1001];
struct temp {
    int index;
    double order;
}company[1001];
int compare(const void *a, const void *b)
{
    return (*(temp *)b).order - (*(temp *)a).order;
}
int main()
{
    int n, m;
    int i, j;
    int count;
    int index;
    int list[1001];

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &budget[i]);
        remain[i] = budget[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &bid[i][j]);
        }
    }
    for (j = 0; j < m; j++) {
        // 这里对每个关键词进行处理
        for (i = 1; i <= n; i++) {
            company[i].index = i;
            company[i].order = ((double)bid[i][j] / budget[i]) * remain[i];
        }
        qsort(&company[1], n, sizeof(company[0]), compare);
//        for (i = 1; i <= n; i++) {
//            printf("%d ", company[i].index);
//        }
//        printf("\n");
        count = 0;
        for (i = 1; i <= n; i++) {
            list[i] = 0;
        }
        for (i = 1; i <= n; i++) {
            index = company[i].index;
            if ((remain[index] >= bid[index][j]) && (bid[index][j] > 0)) {
                remain[index] -= bid[index][j];
                list[index] = 1;
                count++;
            }
            if (count == 100) {
                break;
            }
        }
        printf("%d ", count);
        for (i = 1; i <= n; i++) {
            if (list[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}
