#ifndef __STACK__
#include <Item.h>
typedef struct stack *Stack;
Stack STACKinit(int);
int STACKempty(Stack);
void STACKpush(Stack, Item);
Item STACKpop(Stack);
void STACKdestroy(Stack);
#endif