#include "liushuo.h"


/*
 * @brief 用于计算整数因子
 * @param[in] n: 整数
 */
void PollardRho(int n)
{
    int i, x1, x2, y, k;
    i = 1;
    x1 = Randomi(0, n - 1);
    y = x1;
    k = 2;
    int d;
    while (true) {
        i++;
        x2 = (x1 * x1 - 1) % n;
        d = GCD(abs(y - x2), n);

        if (d != 1 && d != n) {
            printf("%d ", d);
            return;
        }
        if (i == k) {
            y = x2;
            k = 2 * k;
        }
        x1 = x2;
        if (i > 100) {
            printf("no anwser\n");
            break;
        }
    }
}
