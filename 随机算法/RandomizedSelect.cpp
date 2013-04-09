/*
 * 随机选择算法
 * author: 刘硕
 * xmuliushuo@gmail.com
 * xmuliushuo.com
 */
#include "liushuo.h"

/*
 * @brief 随机选择函数
 * @param[in] a: 查找的数组
 * @param[in] p: 查找开始索引
 * @param[in] r: 超着结束索引
 * @param[in] i: 查找第i小的数
 * @return 第i小的数
 */
int RandomizedSelect(int *a, int p, int r, int i)
{
	if (p == r) {
		return a[p];
	}
	int q = RandomizedPartition(a, p, r);
	int k = q - p + 1;
	if (i == k) {
		return a[q];
	}
	else if (i < k) {
		return RandomizedSelect(a, p, q - 1, i);
	}
	else {
		return RandomizedSelect(a, q + 1, r, i - k);
	}
	return -1;
}
