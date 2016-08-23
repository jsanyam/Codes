#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;

    void DFSUtil(int src, int visited[], stack<int> &s);
    void SCC_DFS(int src, int visited[]);
    Graph reverse_graph();
public:
    Graph(int v);
    void print_SCC();
    void add_edge(int src, int dest);
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<int>[vertices];
}

void Graph::add_edge(int src, int dest)
{
    adj[src].push_back(dest);
}

void Graph::DFSUtil(int src, int visited[], stack<int> &s)
{
    visited[src] = 1;
    for(list<int>:: iterator iter = adj[src].begin(); iter != adj[src].end(); iter++)
    {
        if(!visited[*iter])
            DFSUtil(*iter, visited, s);
    }
    s.push(src);
}

void Graph::SCC_DFS(int src, int visited[])
{
    visited[src] = 1;
    cout<<src<<" ";
    for(list<int>:: iterator iter = adj[src].begin(); iter != adj[src].end(); iter++)
    {
        if(!visited[*iter])
            SCC_DFS(*iter, visited);
    }
}

Graph Graph::reverse_graph()
{
    Graph gr(vertices);
    for(int i = 0; i < vertices; i++)
        for(list<int>:: iterator iter = adj[i].begin(); iter != adj[i].end(); iter++)
            gr.adj[*iter].push_back(i);
    return gr;
}

void Graph::print_SCC()
{
    int visited[vertices], current;
    stack<int> s;
    for(int i = 0; i < vertices; i++)
        visited[i] = 0;
    for(int i = 0; i < vertices; i++)
    {
        if(!visited[i])
            DFSUtil(i, visited, s);
    }
    Graph gr = reverse_graph();
    for(int i = 0; i < vertices; i++)
        visited[i] = 0;
    while(!s.empty())
    {
        current = s.top();
        s.pop();
        if(!visited[current])
        {
            gr.SCC_DFS(current, visited);
            cout<<endl;
        }
    }
}

int main()
{
    Graph g(7);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 3);
    g.add_edge(5, 6);
    g.print_SCC();
    return 0;
}
