#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GRAPH.h>
#include <TEST.h>

int testgraphcc(char *name)
{
    strcpy(name, __func__);
    Graph G = GRAPHinit(10);
    GRAPHinsertE(G, EDGE(1, 2));
    GRAPHinsertE(G, EDGE(3, 2));
    GRAPHinsertE(G, EDGE(4, 5));
    int a = GRAPHcc(G);
    GRAPHdestroy(G);
    return a;
}

int testgraphcc1(char *name) {
    strcpy(name, __func__);
    Graph G = GRAPHinit(6);
    GRAPHinsertE(G, EDGE(1, 2));
    GRAPHinsertE(G, EDGE(3, 2));
    GRAPHinsertE(G, EDGE(4, 5));
    int a = GRAPHcc(G);
    GRAPHdestroy(G);
    return a;
}

int testtwocolor(char *name) {
    strcpy(name, __func__);
    Graph G = GRAPHinit(6);
    GRAPHinsertE(G, EDGE(1, 2));
    GRAPHinsertE(G, EDGE(3, 2));
    GRAPHinsertE(G, EDGE(4, 5));
    GRAPHinsertE(G, EDGE(1,3));
    int a = GRAPHtwocolor(G);
    GRAPHdestroy(G);
    return a;
}

int main(void)
{
    assertInt(testgraphcc, 7);
    assertInt(testgraphcc1, 3);
    assertFalse(testtwocolor);
}