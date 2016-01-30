#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph
{
    list<int> *a;
    int size;
    public:
    Graph(int size)
    {
        this->size = size;
        a = new list<int>[size];
    }
    int check_bipartite();
    void push_node(int u, int v);
};

int Graph::check_bipartite()
{
    int color[size];
    for(int j = 0; j<size; j++)
        color[j] = -1;
    color[0] = 1;
    int vertex;
    list<int>::iterator i;
    queue<int> q;
    q.push(0);
    while(q.empty() != true)
    {
        vertex = q.front();
        q.pop();
        for(i = a[vertex].begin(); i != a[vertex].end(); i++)
        {
            if(color[*i] == -1)
            {
                color[*i] = 1 - color[vertex];
                q.push(*i);
            }
            else if(color[*i] == color[vertex])
                return 0;
        }
    }
    return 1;
}

void Graph::push_node(int u, int v)
{
    a[u].push_back(v);
}

int main()
{
    Graph g(4);
    g.push_node(0, 1);
    g.push_node(0, 3);
    //g.push_node(0, 2);
    g.push_node(1, 0);
    g.push_node(1, 2);
    g.push_node(2, 0);
    g.push_node(2, 1);
    g.push_node(2, 3);
    g.push_node(3, 0);
    g.push_node(3, 2);
    g.check_bipartite() ? cout<<"Yes" : cout<<"No";
    return 0;
}
