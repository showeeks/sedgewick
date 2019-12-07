#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

int main(int argc, char *argv[])
{
    int V = atoi(argv[1]), E = atoi(argv[2]);
    Graph G = GRAPHrand(V, E);
    if (V < 20)
        GRAPHshow(G);
    else
        printf("%d vertices, %d edges,", V, E);
    // printf("%d component (s)\n", GRAPHcc(G));
    return 0;
}