#ifndef __UF__
// 并查集类型
typedef struct uf *UF;
// 初始化一个并查集
UF UFinit(int);
// 查找
int UFfind(UF, int, int);
// 并集
void UFunion(UF, int, int);
#endif