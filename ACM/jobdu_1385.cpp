
// 题目描述：
//     输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并输出它的后序遍历序列。

// 输入：
//     输入可能包含多个测试样例，对于每个测试案例，
//     输入的第一行为一个整数n(1<=n<=1000)：代表二叉树的节点个数。
//     输入的第二行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的前序遍历序列。
//     输入的第三行包括n个整数(其中每个元素a的范围为(1<=a<=1000))：代表二叉树的中序遍历序列。

// 输出：
//     对应每个测试案例，输出一行：
//     如果题目中所给的前序和中序遍历序列能构成一棵二叉树，则输出n个整数，代表二叉树的后序遍历序列，每个元素后面都有空格。
//     如果题目中所给的前序和中序遍历序列不能构成一棵二叉树，则输出”No”。

// 样例输入：
//     8
//     1 2 4 7 3 5 6 8
//     4 7 2 1 5 3 8 6
//     8
//     1 2 4 7 3 5 6 8
//     4 1 2 7 5 3 8 6

// 样例输出：

//     7 4 2 5 8 6 3 1 
//     No

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stack>

using namespace std;

int error = 0;

int preorder[1001];
int inorder[1001];

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
};

int FindIndex(int data, int start, int end) 
{
	int i;
	for (i = start; i <= end; ++i) {
		if (inorder[i] == data) {
			return i;
		}
	}
	error = 1;
	return 0;
}

TreeNode *Rebuild(int prestart, int preend, int instart, int inend)
{
	if (prestart > preend) return NULL;
	int mid = preorder[prestart];
	int index = FindIndex(mid, instart, inend);
	if (error) return NULL;
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = mid;
	int leftlength = index - instart;
	node->left = Rebuild(prestart + 1, leftlength + prestart, instart, index - 1);
	node->right = Rebuild(leftlength + prestart + 1, preend, index + 1, preend);
	return node;
}

void PostOrder(TreeNode *root)
{
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

int main()
{
	int n;
	int i;
	while (cin >> n) {
		error = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &preorder[i]);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &inorder[i]);
		}
		TreeNode *root = Rebuild(0, n - 1, 0, n - 1);
		if (error) printf("No\n");
		else {
			PostOrder(root);
			printf("\n");
		}

	}
	return 0;
}
