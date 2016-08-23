#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct edges
{
    int src, dest, dis;
};

struct graph
{
    int vertices, edges;
    struct edges *edge;
};

struct Set
{
    int rank, parent;
};

int Find(struct Set *sets, int x)
{
    if(sets[x].parent != x)
        sets[x].parent = Find(sets, sets[x].parent);
    return sets[x].parent;
}

void Union(struct Set *sets, int xset, int yset)
{
    //xset = Find(x);
    //yset = Find(y);
    if(sets[xset].rank < sets[yset].rank)
    {
        sets[xset].parent = yset;
    }
    else if(sets[xset].rank > sets[yset].rank)
    {
        sets[yset].parent = xset;
    }
    else
    {
        sets[yset].parent = xset;
        sets[xset].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    struct edges *a1 = (struct edges *)a;
    struct edges *b1 = (struct edges *)b;
    return a1->dis > b1->dis;
}

void Kruskal(struct graph *g)
{
    int i = 0, e = 0, xroot, yroot;
    struct Set *sets = new struct Set[g->vertices];
    for(int i = 0; i < g->vertices; i++)
    {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
    int counter = g->vertices - 1;
    struct edges *result = new struct edges[counter];
    qsort(g->edge, g->edges, sizeof(g->edge[0]), myComp);
    while(e < counter)
    {
        xroot = Find(sets, g->edge[i].src);
        yroot = Find(sets, g->edge[i].dest);
        if(xroot != yroot)
        {
            result[e++] = g->edge[i];
            Union(sets, xroot, yroot);
        }
        i++;
    }
    for(int i = 0; i < counter; i++)
        printf("%d--->%d %d\n", result[i].src, result[i].dest, result[i].dis);
}

int main()
{
    struct graph *g = new struct graph;
    g->vertices = 4;
    g->edges = 5;
    g->edge = new struct edges[g->edges];
    for(int i = 0 ; i < g->edges; i++)
        scanf("%d%d%d", &(g->edge[i].src), &(g->edge[i].dest), &(g->edge[i].dis));
    Kruskal(g);
    return 0;
}
