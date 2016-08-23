#include<cstdio>
#include<iostream>
#include<list>
#include<queue>
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

void bfs(struct graph *g, int vertex)
{
    int current;
    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        printf("%d\n", current);
        for(list<int>:: iterator iter = g->l[current].begin(); iter != g->l[current].end(); iter++)
        {
            if(!visited[*iter])
            {
                visited[*iter] = 1;
                q.push(*iter);
            }
        }
    }
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
    bfs(g, 0);
    return 0;
}

