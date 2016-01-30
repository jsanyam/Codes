#include<iostream>
#include<list>
using namespace std;

class Graph
{
    list<int> *adj;
    int vertices;
    public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        adj = new list<int>[vertices];
    }
    void push_node(int u, int v);
    bool isCyclicUtil(bool visited[], bool recstack[], int node);
    bool isCyclic();
};

void Graph::push_node(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(bool visited[], bool recstack[], int node)
{
    if(!visited[node]) //If it had been visited earlier and called form isCyclic()
    {
        visited[node] = true;
        recstack[node] = true;
        list<int>::iterator i;
        for (i = adj[node].begin(); i!=adj[node].end(); i++)
        {
            if(!visited[*i] && isCyclicUtil(visited, recstack, *i))
                return true;
            else if(recstack[*i])
                return true;
        }
    }
    recstack[node] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[vertices];
    bool *recstack = new bool[vertices];
    cout<<"reached";
    for(int j = 0; j<vertices; j++)
    {
        visited[j] = false;
        recstack[j] = false;
    }
    for(int i = 0; i<vertices; i++)
        if(isCyclicUtil(visited, recstack, i))
            return true;
    return false;
}

int main()
{
    Graph g(7);
    g.push_node(0, 1);
    g.push_node(1, 2);
    g.push_node(2, 3);
    g.push_node(0, 4);
    g.push_node(4, 1);
    g.push_node(4, 5);
    g.push_node(5, 6);
    g.push_node(6, 4);
    cout<<"yes";
    g.isCyclic() ? cout<<"Cycle is present" : cout<<"Cycle is not present";
    return 0;
}
