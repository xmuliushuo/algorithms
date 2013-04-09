#include "liushuo.h"

bool Place(int *x, int k);
bool Backtrack(int *x, int stopLV, int *node);

/*
 * @brief 用于判断当前位置是否可行
 * @param[in] x: 
 * @param[in] k: 
 * @return 当前位置是否可行
 */
bool Place(int *x, int k)
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
 * @param[out] node: 已经访问的节点数 
 * @return 是否有解
 */
bool QueensLVB(int *x, int stopLV, int *node)
{
    int k = 1;
    int count;
    int i;
    int ok[1000];
    while (k <= stopLV) {
        count = 0;
        (*node)++;
        for (i = 1; i <= 8; i++) {
            x[k] = i;
            if (Place(x, k)) {
                count++;
                ok[count] = i;
            }
        }
        if (count == 0)
            return false;
        i = ok[Randomi(1, count)];
        //printf("%d ", i);
        //getchar();
        x[k++] = i;
    }
    return Backtrack(x, stopLV + 1, node);
}


/*
 * @brief 回溯算法求解
 * @param[out] x：
 * @param[in] stopLV:
 * @param[out] node: 已经访问的节点数 
 * @return 是否有解
 */
bool Backtrack(int *x, int stopLV, int *node)
{
    int i;
    (*node)++;
    if (stopLV > 8) {
        // 已经计算出结果
        return true;
    }
    else {

        for (i = 1; i <= 8; i++) {
            x[stopLV] = i;
            if (Place(x, stopLV)) {
                if (Backtrack(x, stopLV + 1, node) == true) {
                    return true;
                }
            }
        }
        //return false;
    }
    return false;
}
