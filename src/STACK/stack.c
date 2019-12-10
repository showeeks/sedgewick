#include <STACK.h>
#include <Item.h>
#include <stdlib.h>

struct stack{
    // Item 数组
    Item *s;
    // 栈顶位置
    int N;
};

/**
 * 新建一个 stack
 */
Stack STACKinit(int maxN)
{
    Stack s = malloc(sizeof(*s));
    s->s = malloc(maxN * sizeof(Item));
    s->N = 0;
    return s;
}

/**
 * 清空 stack
 */
int STACKempty(Stack s)
{
    return s->N == 0;
}

void STACKpush(Stack s,Item item)
{
    s->s[s->N++] = item;
}

Item STACKpop(Stack s)
{
    return s->s[--s->N];
}

void STACKdestroy(Stack s) {
    free(s->s);
    free(s);
}