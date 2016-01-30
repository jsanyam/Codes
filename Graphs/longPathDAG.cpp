#include<iostream>
#include<list>
#include<stack>
#include<limits.h>
using namespace std;

struct adjList
{
    int value, distance;
};

class Graph
{
    list<adjList> *adj;
    int vertices;
    public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adj = new list<adjList>[vertices];
    }
    void push_node(int u, int v, int weight);
    void topoSortUtil(int visited[], int node, stack<int> &s);
    void topoSort(stack<int> &s);
    int longPath(int source);
};

void Graph::push_node(int u, int v, int weight)
{
    adj[u].push_back({v, weight});
}

void Graph::topoSortUtil(int visited[], int node, stack<int> &s)
{
    visited[node] = true;
    list<adjList>::iterator i;
    for(i = adj[node].begin(); i!=adj[node].end(); i++)
    {
        if(!visited[(*i).value])
            topoSortUtil(visited, (*i).value, s);
    }
    s.push(node);
}
void Graph::topoSort(stack<int> &s)
{
    int visited[vertices];
    for(int j = 0; j<vertices; j++)
        visited[j] = 0;
    for(int j = 0; j<vertices; j++)
        if(!visited[j])
            topoSortUtil(visited, j, s);
}

int Graph::longPath(int source)
{
    stack<int> s;
    topoSort(s);
    int distances[vertices];
    for(int i = 0; i<vertices; i++)
        distances[i] = INT_MIN;
    distances[source] = 0;
    //while(s.top()!=source)
    //    s.pop();
    while(!s.empty())
    {
        int current = s.top();
        s.pop();
        list<adjList>::iterator j;
        for(j=adj[current].begin(); j!=adj[current].end(); j++)
            if(distances[current] + (*j).distance > distances[(*j).value])
                distances[(*j).value] = distances[current] + (*j).distance;
    }
    int longest = INT_MIN;
    for(int i = 0; i<vertices; i++)
        if(distances[i] > longest)
            longest = distances[i];
    return longest;
}

int main()
{
    Graph g(6);
    g.push_node(0, 1, 5);
    g.push_node(0, 2, 3);
    g.push_node(1, 3, 6);
    g.push_node(1, 2, 2);
    g.push_node(2, 4, 4);
    g.push_node(2, 5, 2);
    g.push_node(2, 3, 7);
    g.push_node(3, 5, 1);
    g.push_node(3, 4, -1);
    g.push_node(4, 5, -2);
    cout<<g.longPath(1)<<endl;
    return 0;
}
