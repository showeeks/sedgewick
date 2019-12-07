#ifndef __GRAPHH__

#define maxV 100

// 边类型
typedef struct
{
    // 边的尾
    int v;
    // 边的头
    int w;
} Edge;

// 边的构造函数
Edge EDGE(int, int);

// 图指针类型
typedef struct graph *Graph;

// 图的初始化函数
Graph GRAPHinit(int);
// 向图插入一条边
void GRAPHinsertE(Graph, Edge);
// 删除图的一条边
void GRAPHremoveE(Graph, Edge);
/**
 * 图的边遍历函数
 * 
 * @param edges 空的边数组，大小必须大于 G 的边的数量
 * @param G 图
 * @return 边的数量
 */
int GRAPHedges(Edge[], Graph G);
// 图的拷贝构造函数
Graph GRAPHcopy(Graph);
// 图的析构函数
void GRAPHdestroy(Graph);
/**
 * 生成随机图
 */
Graph GRAPHrand(int V, int E);
void GRAPHshow(Graph G);
void GRAPHsearch(Graph G);
int GRAPHcc(Graph G);
#endif