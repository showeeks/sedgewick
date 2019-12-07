#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"

int main(int argc, char *argv[])
{
    int V = atoi(argv[1]), E = atoi(argv[2]);
    Graph G = GRAPHrand(V, E);
    if (V < 40)
        GRAPHshow(G);
    else
        printf("%d vertices, %d edges,", V, E);
    GRAPHsearch(G);
    // printf("%d component (s)\n", GRAPHcc(G));
    int cc = GRAPHcc(G);
    printf("there is %d connected components.", cc);
    return 0;
}