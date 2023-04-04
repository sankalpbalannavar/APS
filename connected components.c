#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 1000

typedef struct {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
} graph;

void initialize_graph(graph *g) {
    int i;
    g -> nvertices = 0;
    g -> nedges = 0;
    g -> directed = false;
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
    for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, bool directed) {
    edgenode *p;
    p = malloc(sizeof(edgenode));
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->degree[x]++;
    if (directed == false)
        insert_edge(g,y,x,true);
    else
        g->nedges++;
}

void read_graph(graph *g, bool directed) {
    int i, m, x, y;
    initialize_graph(g);
    scanf("%d %d", &(g->nvertices), &m);
    for (i=1; i<=m; i++) {
        scanf("%d %d",&x,&y);
        insert_edge(g,x,y,directed);
    }
}

void dfs(graph *g, int v, int cc[], int k) {
    edgenode *p;
    cc[v] = k;
    for (p = g->edges[v]; p != NULL; p = p->next) {
        if (cc[p->y] == -1) {
            dfs(g, p->y, cc, k);
        }
    }
}

int connected_components(graph *g, int cc[]) {
    int i, count = 0;
    for (i=1; i<=g->nvertices; i++) cc[i] = -1;
    for (i=1; i<=g->nvertices; i++) {
        if (cc[i] == -1) {
            dfs(g, i, cc, count);
            count++;
        }
    }
    return count;
}

int main() {
    graph g;
    int cc[MAXV+1], i, numcc;
    read_graph(&g, false);
    numcc = connected_components(&g, cc);
    printf("%d connected component(s):\n", numcc);
    for (i=0; i<numcc; i++) {
        printf("Component %d: ", i+1);
        for (int j=1; j<=g.nvertices; j++) {
            if (cc[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    return 0;
}