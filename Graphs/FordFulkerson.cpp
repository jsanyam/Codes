#include<iostream>
#include<queue>
#include<climits>
using namespace std;

#define n 6

int bfs(int rGraph[n][n], int parent[], int s, int t) //Residual Graph and Augmenting Path
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

int FordFulkerson(int Graph[][n], int s, int t)
{
    int rGraph[n][n], parent[n], max_flow = INT_MAX, total_flow = 0;
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
            rGraph[v][u] += max_flow;
        }
        total_flow += max_flow;
    }
    return total_flow;
}

int main()
{
    int Graph[6][6] = { 0, 16, 13, 0, 0, 0,
                        0, 0, 10, 12, 0, 0,
                        0, 4, 0, 0, 14, 0,
                        0, 0, 9, 0, 0, 20,
                        0, 0, 0, 7, 0, 4,
                        0, 0, 0, 0, 0, 0
                      };
    cout<<"The maximum flow is "<<FordFulkerson(Graph, 0, 5);
    return 0;
}
