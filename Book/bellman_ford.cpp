#include<cstdio>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<list>
#include<vector>
using namespace std;

int *dist;

struct edge
{
    int src, dest, dis;
};

struct graph
{
    int vertices, edges;
    struct edge *edge;
};

void initialise_dist(int size)
{
    dist = new int[size];
    for(int i = 0; i < size; i++)
        dist[i] = INT_MAX;
}

void bellman_ford(struct graph *g, int source)
{
    initialise_dist(g->vertices);
    dist[source] = 0;
    for(int i = 0; i < (g->vertices - 1); i++)
        for(int j = 0; j < g->edges; j++)
            if(dist[g->edge[j].src] != INT_MAX && dist[g->edge[j].dest] > dist[g->edge[j].src] + g->edge[j].dis)
                dist[g->edge[j].dest] = dist[g->edge[j].src] + g->edge[j].dis;
    for(int j = 0; j < g->edges; j++)
        if(dist[g->edge[j].src] != INT_MAX && dist[g->edge[j].dest] > dist[g->edge[j].src] + g->edge[j].dis)
        {
            printf("Negative weight cycle exists");
            return;
        }
    for(int i = 0; i < g->vertices; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

int main()
{
    graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 5;
    g->edges = 8;
    g->edge = (struct edge *)malloc(sizeof(struct edge) * g->edges);
    for(int i = 0; i < g->edges; i++)
        scanf("%d%d%d", &(g->edge[i].src), &(g->edge[i].dest), &(g->edge[i].dis));
    bellman_ford(g, 0);
}
