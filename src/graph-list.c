#include <stdlib.h>
#include "GRAPH.h"

// 链表指针类型
typedef struct node *link;

// 链表类型
struct node
{
    // 当前节点
    int v;
    // 下一个节点
    link next;
};

/**
 * 邻接链表表示的图类型
 */
struct graph
{
    // 顶点的数量
    int V;
    // 边的数量
    int E;
    // 链表指针数组
    link *adj;
};

/**
 * 生成一条新的邻接链表边
 */
link NEW(int v, link next)
{
    link x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}

/**
 * 邻接链表图的构造函数
 * 创建一个有V个节点，0个边的图
 * 
 * @param V 节点的数量
 * @return 图指针，指向构造好的图对象
 */
Graph GRAPHinit(int V)
{
    // 空的Graph对象
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    // 空的链表指针数组，长度为 V
    G->adj = malloc(V * sizeof(link));
    for (int v = 0; v < V; v++)
    {
        // 链表指针指向空
        G->adj[v] = NULL;
    }
    return G;
}

/**
 * 向图插入一条新的边
 * 
 * @param G 图
 * @param e 边
 */
void GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v;
    int w = e.w;
    G->adj[v] = NEW(w, G->adj[v]);
    G->adj[w] = NEW(v, G->adj[w]);
    G->E++;
}

/**
 * 图的所有边
 * 
 * @param edges 空的边数组
 * @param G 图
 * @return 边的数量
 */
int GRAPHedges(Edge edges[], Graph G)
{
    int E = 0;
    for (int v = 0; v < G->V; v++)
    {
        for (link t = G->adj[v]; t != NULL; t = t->next)
        {
            if (v < t->v)
            {
                edges[E++] = EDGE(v, t->v);
            }
        }
    }
}