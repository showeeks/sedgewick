#include <stdlib.h>
#include <UF.h>

// 并查集的底层数据结构
struct uf {
    // 记录并查集中每个元素的父亲是谁
    // 指标是并查集中元素的序号，值是该元素的父亲
    int *id;
    // 记录并查集中每个连通分量的大小
    // 指标是并查集中连通分量的序号
    int *sz;
};


/**
 * 新建一个并查集对象
 * 
 * @param N 生成的并查集要求有n个元素
 * @return 并查集对象指针
 */
UF UFinit(int N)
{
    UF uf = malloc(sizeof(struct uf));
    uf->id = malloc(N * sizeof(int));
    uf->sz = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        uf->id[i] = i;
        uf->sz[i] = i;
    }
    return uf;
}

/**
 * 并查集查找操作的辅助函数
 * 这种并查集的实现是所谓的快速合并的并查集
 * id 数组表示的是元素的父亲是什么
 * 
 * @param uf
 * @param x
 * @return x 的祖先
 */
static int find(UF uf,int x)
{
    int i = x;
    while (i != uf->id[i])
        i = uf->id[i];
    return i;
}

/**
 * 将p,q放到同一个连通分支
 * 
 */
void UFunion(UF uf, int p, int q)
{
    // p 的祖先
    int i = find(uf, p);
    // q 的祖先
    int j = find(uf, q);
    if (i == j)
        return;
    if (i > j)
    {
        // 将 i 连接到 j 上
        uf->id[i] = j;
        uf->sz[j] += uf->sz[i];
        return;
    }
    else
    {
        uf->id[j] = i;
        uf->sz[j] += uf->sz[i];
    }
}

/**
 * 查找p, q
 * 
 * @param uf 并查集
 * @param p 元素
 * @param q 元素
 * 
 * @return p, q连通返回true, p, q 不连通返回false
 */
int UFfind(UF uf, int p, int q)
{
    return find(uf, p) == find(uf, q);
}