#include <STACK.h>
#include <TEST.h>
#include <string.h>
#include <stdlib.h>

int teststack(char *name)
{
    strcpy(name, __func__);
    STACKinit(10);
    STACKpush(1);
    STACKpush(2);
    STACKpush(3);
    int res = 1;
    res = res && STACKpop() == 3;
    res = res && STACKpop() == 2;
    res = res && STACKpop() == 1;
    return res;
}

int main(void)
{
    assertTrue(teststack);
}