#include <stdio.h>
#include <stdlib.h>
#include <UF.h>
#include <TEST.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

static int cnt = 0;

int testUF1(char *name)
{
    strcpy(name, __func__);
    UF uf = UFinit(10);
    UFunion(uf, 1, 2);
    UFunion(uf, 3, 4);
    int res = !UFfind(uf, 1, 3);
    free(uf);
    return res;
}

int testUF2(char *name)
{
    strcpy(name, __func__);
    UF uf = UFinit(10);
    UFunion(uf, 1, 2);
    UFunion(uf, 1, 3);
    int res = UFfind(uf, 2, 3);
    free(uf);
    return res;
}

void test(int (*foo)(void))
{
    if (foo())
        printf("test %d succeeded.\n", ++cnt);
    else
        printf("test %d failed.\n", ++cnt);
}

// #ifdef TEST
// void UFtest(void)
// #else
int main(int argc, char **argv)
// #endif
{
    assertTrue(testUF1);
    assertTrue(testUF2);
    return 0;
}