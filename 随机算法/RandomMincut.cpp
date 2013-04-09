/*
 * @brief 
 * @author 刘硕
 */

#include "RandomMincut.h"

/*
 * @brief the consturct funciton of class RandomMincut
 * @param [in] nodeNum: 图的结点数
 */
RandomMincut::RandomMincut(int nodeNum)
{
    m_graph = new (int *)[nodeNum];
    for (int i = 0; i < nodeNum; i++) {
        m_graph[i] = new int[nodeNum];
    }
}

/*
 * @brief 析构函数
 */
RandomMincut::~RandomMincut()
{
    for (int i = 0; i < nodeNum; i++) {
        delete[] m_graph[i];
    }
    delete[] m_graph;
}

/*
 * @brief 输入算法所需参数
 * @return 输入的参数是否符合规范
 */
bool RandomMincut::input()
{
    int i, j;
    printf("please input the adjacency matrix:\n");
    for (i = 0; i < nodeNum; i++) {
        for (j = 0; j < nodeNum; j++) {
            scanf("%d", &m_graph[i][j]);
        }
    }
    // 这里需要邻接矩阵进行检查，确保边的权值为正数，且对称
    for (i = 0; i < nodeNum; i++) {
        for (j = i; j < nodeNum; j++) {
            if ((m_graph[i][j] < 0) && (m_graph[i][j] != m_graph[j][i])) {
                return false;
            }
        }
    }
    return true;
}

/*
 * @brief 执行算法
 */
void RandomMincut::execute()
{
    
}