/*
 * @brief 
 * @author 刘硕
 */

#ifndef RANDOMMINCUT
#define RANDOMMINCUT

#include "liushuo.h"

class RandomMincut
{
public:
    RandomMincut(int);
    ~RandomMincut();
    bool input();
    void execute();
    void display();
private:
    int **m_graph;// 邻接矩阵

};

#endif
