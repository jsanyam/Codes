#include<cstdio>
#include<iostream>
#include<list>
#include<cstdlib>
#include<queue>
using namespace std;

struct graph
{
    int vertices, edges;
    list<int> *l;
};

int *indegree;

void intialise_indegree(int size)
{
    indegree = new int[size];
    for(int i = 0; i < size; i++)
        indegree[i] = 0;
}

void insert_edge(struct graph *g, int source, int dest)
{
    g->l[source].push_back(dest);
    indegree[dest] += 1;
    //g->l[dest].push_back(source);
}

void topo_sort(struct graph *g)
{
    int current, count = 0;
    queue<int> q;
    for(int i = 0; i < g->vertices; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        current = q.front();
        printf("%d ", current);
        q.pop();
        for(list<int>:: iterator iter = g->l[current].begin(); iter != g->l[current].end(); iter++)
        {
            indegree[*iter]--;
            if(indegree[*iter] == 0)
                q.push(*iter);
        }
        count++;
    }
    if(count != g->vertices)
        printf("\nGraph has cycles\n");
}

int main()
{
    int source, dest;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 6;
    g->edges = 6;
    g->l = new list<int>[g->vertices];
    intialise_indegree(g->vertices);
    for(int i = 0; i < g->edges; i++)
    {
        scanf("%d%d", &source, &dest);
        insert_edge(g, source, dest);
    }
    topo_sort(g);
    return 0;
}
