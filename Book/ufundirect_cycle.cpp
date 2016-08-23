#include<iostream>
using namespace std;

struct Edge
{
    int v1, v2;
};

class Graph
{
    int vertices, edges;
    int Find(int parent[], int index);
    void Union(int parent[], int index1, int index2);
public:
    struct Edge *edge;
    Graph(int v, int e);
    bool detect_cycle();
};

Graph::Graph(int v, int e)
{
    vertices = v;
    edges = e;
    edge = new struct Edge[edges];
}

int Graph:: Find(int parent[], int index)
{
    if(parent[index] == -1)
        return index;
    Find(parent, parent[index]);
}

void Graph:: Union(int parent[], int index1, int index2)
{
    parent[index1] = index2;
}

bool Graph:: detect_cycle()
{
    int parent[vertices], p1, p2;
    for(int i = 0; i < vertices; i++)
        parent[i] = -1;
    for(int i = 0; i < edges; i++)
    {
        p1 = Find(parent, edge[i].v1);
        p2 = Find(parent, edge[i].v2);
        if(p1 == p2)
            return true;
        Union(parent, p1, p2);
    }
    return false;
}

int main()
{
    Graph g(3, 3);
    g.edge[0].v1 = 0;
    g.edge[0].v2 = 1;
    g.edge[1].v1 = 1;
    g.edge[1].v2 = 2;
    g.edge[2].v1 = 0;
    g.edge[2].v2 = 2;
    if(g.detect_cycle())
        cout<<"graph is cyclic"<<endl;
    else
        cout<<"graph is acyclic"<<endl;
    return 0;
}
