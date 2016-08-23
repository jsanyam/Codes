/* approximate algorithm, max(colors) <= max(degree) + 1 */
#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;

public:
    Graph(int v);
    void add_edge(int v, int w);
    void graph_color();
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::graph_color()
{
    int color[vertices], assigned[vertices];
    for(int i = 0; i < vertices; i++)
    {
        color[i] = -1;
        assigned[i] = 0;
    }
    color[0] = 0;
    for(int i = 1; i < vertices; i++)
    {
        for(list<int>::iterator iter = adj[i].begin(); iter != adj[i].end(); iter++)
            if(color[*iter] != -1)
                assigned[color[*iter]] = 1;
        for(int j = 0; j < vertices; j++)
            if(assigned[j] == 0)
            {
                color[i] = j;
                break;
            }
        for(list<int>::iterator iter = adj[i].begin(); iter != adj[i].end(); iter++)
            if(color[*iter] != -1)
                assigned[color[*iter]] = 0;
    }
    for(int i = 0; i < vertices; i++)
        cout<<color[i]<<" ";
    cout<<endl;
}

int main()
{
    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 3);
    g.add_edge(3, 5);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.graph_color();
    return 0;
}
