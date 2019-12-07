#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

struct graph
{
    int V;
    int E;
    int **adj;
};

Edge EDGE(int v, int w) {
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
