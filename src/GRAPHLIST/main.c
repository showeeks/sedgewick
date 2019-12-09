#include <stdio.h>
#include <stdlib.h>
#include <GRAPH.h>
#include <TEST.h>

int testgraph1(void)
{
    Graph G = GRAPHinit(10);
    GRAPHinsertE(G, EDGE(1, 2));
    GRAPHinsertE(G, EDGE(3, 2));
    GRAPHinsertE(G, EDGE(4, 5));
    int a = GRAPHcc(G);
    assertInt(a, 2);
    GRAPHdestroy(G);
}

int main(void)
{
}