/**
 * 图的矩阵表示的实现和相关算法
 * 如果实现与矩阵表示是相关的，就必须写在该文件中
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

/**
 * 图的完整类型
 * 图的具体属性不允许外部访问
 */
struct graph
{
    // 图的顶点数量
    int V;
    // 图的边数量
    int E;
    // 邻接矩阵，adj[v] 表示
    int **adj;
};

Edge EDGE(int v, int w)
{
    Edge *e = malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    return *e;
}

/**
 * 矩阵的初始化函数，构造一个矩阵出来
 */
int **MATRIXint(int r, int c, int val)
{
    int **t = malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        t[i] = malloc(c * sizeof(int));
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            t[i][j] = val;
        }
    }
    return t;
}

Graph GRAPHinit(int V)
{
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

/**
 * 在邻接矩阵中添加关联关系
 */
void GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

/**
 * 在邻接矩阵中删除关联关系
 */
void GRAPHremoveE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E--;
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int GRAPHedges(Edge edges[], Graph G)
{
    int E = 0;
    for (int v = 0; v < G->V; v++)
    {
        for (int w = 0; w < G->V; w++)
        {
            if (G->adj[v][w] == 1)
                edges[E++] = EDGE(v, w);
        }
    }
    return E;
}

/**
 * 将图打印出来的函数
 */
void GRAPHshow(Graph G)
{
    printf("%d vertices, %d edges\n", G->V, G->E);
    for (int i = 0; i < G->V; i++)
    {
        printf("%2d:", i);
        for (int j = 0; j < G->V; j++)
        {
            if (G->adj[i][j] == 1)
                printf(" %2d", j);
        }
        printf("\n");
    }
}

int randV(Graph G)
{
    return G->V * (rand() / (RAND_MAX + 1.0));
}

Graph GRAPHrand(int V, int E)
{
    // 先创建一个空的图
    Graph G = GRAPHinit(V);
    // 开始构造边
    while (G->E < E)
    {
        GRAPHinsertE(G, EDGE(randV(G), randV(G)));
    }
    return G;
}

// 已访问的顶点数量
static int cnt;
// pre 数组表示该图是否已被访问
static int pre[maxV];
// 在该文件中 search 的实现是 DFS
#define dfsR search

/**
 * 深度优先搜索
 * 深度优先搜索的特点是它是基于栈的，递归是最自然的形式
 * 
 * @param G 图
 * @param e 边
 */
void dfsR(Graph G, Edge e)
{
    // 访问 e 的头 w
    int w = e.w;
    // 将顶点 w 标记为已访问过
    pre[w] = cnt++;
    // 访问 w 的所有邻居
    for (int t = 0; t < G->V; t++)
    {
        // w 与 t 之间存在边
        if (G->adj[w][t] != 0)
        {
            // t 未被访问过
            if (pre[t] == -1)
            {
                dfsR(G, EDGE(w, t));
            }
        }
    }
}

/**
 * 搜索一个邻接矩阵表示的图
 */
void GRAPHsearch(Graph G)
{
    // 首先初始化静态变量 cnt
    cnt = 0;
    // 将所有顶点初始化为未访问过
    for (int v = 0; v < G->V; v++)
    {
        pre[v] = -1;
    }
    // 尝试访问所有节点
    for (int v = 0; v < G->V; v++)
    {
        if (pre[v] == -1)
        {
            search(G, EDGE(v, v));
        }
    }
}
