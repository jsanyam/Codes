#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int n;

int bfs(int *rGraph[], int parent[], int s, int t) //Residual Graph and Augmenting Path
{
    int visited[n];
    for(int i = 0; i<n; i++)
        visited[i] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<n; i++)
            if(visited[i] == 0 && rGraph[u][i] > 0)
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = u;
            }
    }
    return (visited[t]==1);
}

int FordFulkerson(int *Graph[], int s, int t)
{
    int *rGraph[n], parent[n], max_flow = INT_MAX, total_flow = 0;
    for(int i = 0; i<n; i++)
            rGraph[i] = new int[n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            rGraph[i][j] = Graph[i][j];
    while(bfs(rGraph, parent, s, t))
    {
        max_flow = INT_MAX;
        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            max_flow = min(max_flow, rGraph[u][v]);
        }
        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= max_flow;
            rGraph[v][u] += max_flow; //Do BFS ever work on back edges?
        }
        total_flow += max_flow;
    }
    return total_flow;
}

int main()
{
    int t, root, vertex, source, sink, no;
    cin>>t;
    while(t--)
    {
        root = 0;
        cin>>n;
        source = 0;
        sink = n-1;
        int *Graph[n];
        for(int i = 0; i<n; i++)
            Graph[i] = new int[n];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                Graph[i][j] = 0;
        int loop = n-1;
        while(loop--)
        {
            cin>>no;
            for(int i = 0; i<no; i++)
            {
                cin>>vertex;
                if(root == source || vertex-1 == sink)
                    Graph[root][vertex-1] = 1;
                else
                    Graph[root][vertex-1] = n;
            }
            root++;
        }
        cout<<FordFulkerson(Graph, source, sink)<<endl;
    }
    return 0;
}
