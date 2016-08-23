#include<cstdio>
#include<iostream>
#include<list>
#include<cstdlib>
#include<stack>
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

void insert_edge(struct graph *g, int source, int dest)
{
    g->l[source].push_back(dest);
    //g->l[dest].push_back(source);
}

void topo_sort_util(struct graph *g, int vertex, stack<int> &s)
{
    visited[vertex] = 1;
    for(list<int>:: iterator iter = g->l[vertex].begin(); iter != g->l[vertex].end(); iter++)
        if(!visited[*iter])
            topo_sort_util(g, *iter, s);
    //cout<<vertex<<endl;
    s.push(vertex);
}

void topo_sort(struct graph *g)
{
    stack<int> s;
    for(int i = 0; i < g->vertices; i++)
        if(!visited[i])
            topo_sort_util(g, i, s);
    cout<<"hello"<<endl;
    while(!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
}

int main()
{
    int source, dest;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 6;
    g->edges = 6;
    g->l = new list<int>[g->vertices];
    for(int i = 0; i < g->edges; i++)
    {
        scanf("%d%d", &source, &dest);
        insert_edge(g, source, dest);
    }
    intialise_visited(g->vertices);
    topo_sort(g);
    return 0;
}
