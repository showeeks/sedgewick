#include <stdio.h>
#include <stdlib.h>
#include <UF.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv)
{
    int p, q, N = atoi(argv[1]);
    UF uf = UFinit(N);
    while (scanf("%d %d", &p, &q) == 2)
        if (!UFfind(uf, p, q))
        {
            UFunion(uf, p, q);
            printf(" %d %d\n", p, q);
        }
}

int testUF1()
{
    UF uf = UFinit(10);
    UFunion(uf, 1, 2);
    UFunion(uf, 3, 4);
    int res = !UFfind(uf, 1, 3);
    free(uf);
    return res;
}