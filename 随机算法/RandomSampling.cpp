/*
 * 随机取样算法
 * author: 刘硕
 * xmuliushuo@gmail.com
 * xmuliushuo.com
 */

#include "liushuo.h"

/*
 * @brief 随机取样函数
 * @param[in] set: 要取样的集合
 * @param[in] n: 取样集合的大小
 * @param[in] m: 样本大小（m < n）
 * @param[out] sample: 取得的样本
 */
void RandomSampling(int *set, int n, int m, int *sample)
{
    if (m >= n) {
        printf("error: m >= n\n");
        return;
    }
    int *flag = new int[n];
    for (int i = 0; i < n; i++) {
        flag[i] = 0;
    }
    int k = 0;
    int r;
    
    while (k < m) {
        r = Randomi(0, n - 1);
        if (!flag[r]) {        
            //printf("%d\n", k);
            sample[k] = r;
            //printf("----");
            flag[r] = 1;
            k++;
        }
    }
    delete[] flag;
}
