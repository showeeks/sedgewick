#include <STACK.h>
#include <TEST.h>
#include <string.h>
#include <stdlib.h>

Item NewItem(int i)
{
    Item a = malloc(sizeof(int));
    *a = i;
    return a;
}

int teststack(char *name)
{
    strcpy(name, __func__);
    STACKinit(10);
    STACKpush(NewItem(1));
    STACKpush(NewItem(2));
    STACKpush(NewItem(3));
    int res = 1;
    res = res && *(STACKpop()) == 3;
    res = res && *(STACKpop()) == 2;
    res = res && *(STACKpop()) == 1;
    return res;
}

int main(void)
{
    assertTrue(teststack);
}