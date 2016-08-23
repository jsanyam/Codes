#include<iostream>
#include<list>
#include<stack>
#include<climits>
using namespace std;

struct node
{
    int index, dis;
};

class Graph
{
    int vertices;
    list<struct node> *adj;
    void topo_sort_util(stack<int>& s, int visited[], int index);

public:
    Graph(int v);
    void add_edge(int v, int w, int dis);
    void DAG_longdist(int src);
};

Graph::Graph(int v)
{
    vertices = v;
    adj = new list<struct node>[v];
}

void Graph::add_edge(int v, int w, int dis)
{
    adj[v].push_back({w, dis});
}

void Graph::DAG_longdist(int src)
{
    int visited[vertices], dist[vertices], current;
    stack<int> s;
    for(int i = 0; i < vertices; i++)
        visited[i] = 0;
    for(int i = 0; i < vertices; i++)
        if(!visited[i])
            topo_sort_util(s, visited, i);
    for(int i = 0; i < vertices; i++)
        dist[i] = INT_MIN;
    dist[src] = 0;
    while(!s.empty())
    {
        current = s.top();
        cout<<current<<endl;
        s.pop();
        for(list<struct node>::iterator iter = adj[current].begin(); iter != adj[current].end(); iter++)
            if(dist[(*iter).index] < dist[current] + (*iter).dis)
                dist[(*iter).index] = dist[current] + (*iter).dis;
    }
    for(int i = 0; i < vertices; i++)
        (dist[i] == INT_MIN)? cout<<"INF " : cout<<dist[i]<<" ";
    cout<<endl;
}

void Graph::topo_sort_util(stack<int> &s, int visited[], int index)
{
    visited[index] = 1;
    for(list<struct node>::iterator iter = adj[index].begin(); iter != adj[index].end(); iter++)
        if(!visited[(*iter).index])
            topo_sort_util(s, visited, (*iter).index);
    s.push(index);
}

int main()
{
    Graph g(6);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 6);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 5, 1);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);
    g.DAG_longdist(1);
    return 0;
}
