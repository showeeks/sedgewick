#include <STACK.h>
#include <TEST.h>
#include <string.h>
#include <stdlib.h>

struct item
{
    int value;
};

Item NewItem(int v) {
    Item i = malloc(sizeof(*i));
    i->value = v;
    return i;
}



int teststack(char *name)
{
    strcpy(name, __func__);
    Item a = NewItem(1);
    Item b = NewItem(2);
    Item c = NewItem(3);
    Stack s = STACKinit(10);
    STACKpush(s,a);
    STACKpush(s,b);
    STACKpush(s,c);
    int res = 1;
    res = res && STACKpop(s)->value == 3;
    res = res && STACKpop(s)->value == 2;
    res = res && STACKpop(s)->value == 1;
    free(a);
    free(b);
    free(c);
    STACKdestroy(s);
    return res;
}

int main(void)
{
    assertTrue(teststack);
}