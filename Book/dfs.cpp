#include<cstdio>
#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;

struct graph
{
    int vertices, edges;
    list<int> *l;
};

int *visited;

void intialise_visited(int size)
{
    visited = new int[size];
    for(int i = 0; i < size; i++)
        visited[i] = 0;
}

void dfs(struct graph *g, int vertex)
{
    visited[vertex] = 1;
    for(list<int>::iterator i = g->l[vertex].begin(); i != g->l[vertex].end(); i++)
    {
        if(!visited[*i])
            dfs(g, *i);
    }
    printf("%d\n", vertex);
}

void insert_edge(struct graph *g, int source, int dest)
{
    g->l[source].push_back(dest);
    g->l[dest].push_back(source);
}

int main()
{
    int source, dest;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 8;
    g->edges = 8;
    g->l = new list<int>[g->vertices];
    for(int i = 0; i < g->edges; i++)
    {
        scanf("%d%d", &source, &dest);
        insert_edge(g, source, dest);
    }
    intialise_visited(g->vertices);
    dfs(g, 0);
    return 0;
}
