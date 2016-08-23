#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;
    bool detect_cycleUtil(int src, int visited[], int parent);
public:
    Graph(int v);
    void insert_edge(int src, int dest);
    bool detect_cycle();
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<int>[vertices];
}

void Graph:: insert_edge(int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool Graph:: detect_cycle()
{
    int visited[vertices];
    for(int i = 0; i < vertices; i++)
        visited[i] = 0;
    for(int i = 0; i < vertices; i++)
        if(!visited[i] && detect_cycleUtil(i, visited, -1))
            return true;
    return false;
}

bool Graph:: detect_cycleUtil(int src, int visited[], int parent)
{
    visited[src] = 1;
    for(list<int>:: iterator iter = adj[src].begin(); iter != adj[src].end(); iter++)
    {
        if(!visited[*iter])
        {
            if(detect_cycleUtil(*iter, visited, src))
                return true;
        }
        else if(*iter != parent)
            return true;
    }
    return false;
}

int main()
{
    Graph g(4);
    g.insert_edge(0, 1);
    g.insert_edge(0, 2);
    g.insert_edge(2, 0);
    g.insert_edge(2, 3);
    if(g.detect_cycle())
        cout<<"Cycle detected"<<endl;
    else
        cout<<"Cycle not detected"<<endl;
    return 0;
}
