#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<list>
using namespace std;

struct graph
{
    int vertices, edges;
    list<int> *vertex;
};

int *visited, *parent, *disc, *low;

void add_edge(struct graph *g, int a, int b)
{
    g->vertex[a].push_back(b);
    g->vertex[b].push_back(a);
}

void initialize(int vertices)
{
    visited = new int[vertices];
    parent = new int[vertices];
    disc = new int[vertices];
    low = new int[vertices];
    for(int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }
}

void cut_edges(struct graph *g, int src)
{
    static int time = 0;
    int children = 0;
    visited[src] = 1;
    disc[src] = low[src] = ++time;
    for(list<int>::iterator iter = g->vertex[src].begin(); iter != g->vertex[src].end(); iter++)
    {
        if(!visited[*iter])
        {
            parent[*iter] = src;
            children++;
            cut_edges(g, *iter);
            low[src] = min(low[src], low[*iter]);
            //if(parent[src] == -1 && children >= 2)
            //    ap[src] = 1;
            if(disc[src] < low[*iter])
                printf("%d---%d\n", src, *iter);
        }
        else if(*iter != parent[src])
        {
            low[src] = min(low[src], disc[*iter]);
        }
    }
}

int main()
{
    int src, dest;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 7;
    g->edges = 8;
    g->vertex = new list<int>[g->vertices];
    for(int i = 0; i < g->edges; i++)
    {
        scanf("%d%d", &src, &dest);
        add_edge(g, src, dest);
    }
    initialize(g->vertices);
    for(int i = 0; i < g->vertices; i++)
        if(!visited[i])
            cut_edges(g, i);
    return 0;
}

