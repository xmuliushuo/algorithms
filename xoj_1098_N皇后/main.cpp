#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool Place(int *x, int k);
bool Backtrack(int *x, int stopLV, int *node);
int n;
int x[21];
bool Place(int k);
bool QueensLVB(int stopLV);
bool Backtrack(int stopLV);
/*
 * @brief 得到[i, j]的随机整数
 * @param[in] i:
 * @param[in] j:
 */
int randomi(int i, int j)
{
    return i + rand() % (j - i + 1);
}

int main()
{
    scanf("%d", &n);
    srand(time(NULL));
    while (true) {
        if (QueensLVB(n) == true) {
            break;
        }
    }
    return 0;
}
/*
 * @brief 用于判断当前位置是否可行
 * @param[in] x:
 * @param[in] k:
 * @return 当前位置是否可行
 */
bool Place(int k)
{
    int i;
    for (i = 1; i <= k - 1; i++) {
        if (((k - i) == (x[i] - x[k])) || (x[i] == x[k]) || (k - i) == - (x[i] - x[k])) {
            return false;
        }
    }
    return true;
}

/*
 * @brief 随机算法求解
 * @param[out] x:
 * @param[in] stopLV:
 * @return 是否有解
 */
bool QueensLVB(int stopLV)
{
    int k = 1;
    int count;
    int i;
    int ok[1000];
    while (k <= stopLV) {
        count = 0;
        for (i = 1; i <= n; i++) {
            x[k] = i;
            if (Place(k)) {
                count++;
                ok[count] = i;
            }
        }
        if (count == 0)
            return false;
        i = ok[randomi(1, count)];
        x[k++] = i;
    }
    return Backtrack(stopLV + 1);
}


/*
 * @brief 回溯算法求解
 * @param[out] x：
 * @param[in] stopLV:
 * @return 是否有解
 */
bool Backtrack(int stopLV)
{
    int i;
    if (stopLV > n) {
        // 已经计算出结果
        for (i = 1; i <= n; i++) {
            printf("%d %d\n", i, x[i]);
        }
        return true;
    }
    else {

        for (i = 1; i <= 8; i++) {
            x[stopLV] = i;
            if (Place(stopLV)) {
                if (Backtrack(stopLV + 1) == true) {
                    return true;
                }
            }
        }
    }
    return false;
}
