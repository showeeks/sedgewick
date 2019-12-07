#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

Edge EDGE(int v, int w)
{
    Edge *e = malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    return *e;
}

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
    // 计算连通图问题
    int *cc;
    // 计算二分图问题
    int *color;
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
    // 边的数量
    int E = 0;
    // 顶点
    for (int v = 0; v < G->V; v++)
        // 顶点 v 的邻接链表
        for (link t = G->adj[v]; t != NULL; t = t->next)
            if (t->v > v)
                edges[E++] = EDGE(v, t->v);
}

void GRAPHshow(Graph G)
{
    printf("%d vertices, %d edges\n", G->V, G->E);
    for (int v = 0; v < G->V; v++)
    {
        printf("%2d:", v);
        for (link t = G->adj[v]; t != NULL; t = t->next)
            printf(" %2d", t->v);
        printf("\n");
    }
}

int randV(Graph G)
{
    return G->V * (rand() / (RAND_MAX + 1.0));
}

Graph GRAPHrand(int V, int E)
{
    srand(time(NULL));
    // 先创建一个空的图
    Graph G = GRAPHinit(V);
    // 开始构造边
    while (G->E < E)
        GRAPHinsertE(G, EDGE(randV(G), randV(G)));
    return G;
}

// 已访问的顶点数量
static int cnt;
// pre 数组表示该图是否已被访问
static int pre[maxV];
#define dfsR search

/**
 * 遍历一个连通分支
 */
void dfsR(Graph G, Edge e)
{
    int w = e.w;
    pre[w] = cnt++;
    printf("-> %d", w);
    // 遍历链表 adj[w]
    for (link t = G->adj[w]; t != NULL; t = t->next)
        if (pre[t->v] == -1)
            dfsR(G, EDGE(t->v, t->v));
}

void dfsReuler(Graph G, Edge e)
{
    pre[e.w] = cnt++;
    printf("-%d", e.w);
    for (link t = 0; t != NULL; t = t->next)
        if (pre[t->v] == -1)
            dfsReuler(G, EDGE(e.w, t->v));
        // t-> v 是 w 的邻居
        // e.v 是 w 的父亲
        // 如果邻居 < 父亲说明成环
        else if (pre[t->v] < pre[e.v])
            printf("-%d-%d", t->v, e.w);
    if (e.v != e.w)
        printf("-%d", e.v);
    else
        printf("\n");
}

/**
 * 使用 DFS 计算所有的连通分量
 * 
 * @param G 图
 * @param v 访问的顶点
 * @param id 连通分量的 id
 */
void dfsRcc(Graph G, int v, int id)
{
    G->cc[v] = id;
    for (link t = G->adj[v]; t != NULL; t = t->next)
        if (G->cc[t->v] == -1)
            dfsRcc(G, t->v, id);
}

int GRAPHcc(Graph G)
{
    int id = 0;
    G->cc = malloc((G->V) * sizeof(int));
    for (int v = 0; v < G->V; v++)
        G->cc[v] = -1;
    for (int v = 0; v < G->V; v++)
        if (G->cc[v] == -1)
            dfsRcc(G, v, id++);
    return id;
}

/**
 * 遍历整个图
 */
void GRAPHsearch(Graph G)
{
    cnt = 0;
    for (int v = 0; v < G->V; v++)
        pre[v] = -1;
    for (int v = 0; v < G->V; v++)
        if (pre[v] == -1)
        {
            printf("%d", v);
            search(G, EDGE(v, v));
            printf("\n");
        }
}

/**
 * @return 染色成功返回true, 染色失败返回false
 */
int dfsRcolor(Graph G, int v, int c)
{
    for (link t = 0; t != NULL; t = t->next)
        if (G->color[t->v] == -1)
            // 如果子搜索失败，返回false
            if (!dfsRcolor(G, t->v, 1 - c))
                return 0;
            // 如果邻居和当前节点颜色一样，返回false
            else if (G->color[t->v] != c)
                return 0;
    return 1;
}

/**
 * 
 */
int GRAPHtwocolor(Graph G)
{
    G->color = malloc(G->V * sizeof(int));
    for (int v = 0; v < G->V; v++)
        G->color[v] = -1;
    for (int v = 0; v < G->V; v++)
        if (G->color[v] == -1)
            if (!dfsRcolor(G, v, 0))
                return 0;
}

/**
 * 判断 v 和 w 是否在同一个连通分支
 */
int GRAPHconnect(Graph G, int v, int w)
{
    return G->cc[v] == G->cc[w];
}