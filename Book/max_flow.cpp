#include<iostream>
#include<queue>
#include<climits>
using namespace std;

#define n 6

int bfs(int s, int t, int aGraph[][n], int parent[])
{
    int visited[n], current;
    queue<int> q;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        for(int i = 0; i < n; i++)
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                parent[i] = current;
            }
    }
    return (visited[t] == 1);
}

int max_flow(int s, int t, int adj[][n])
{
    int aGraph[n][n], min_flow, maxFlow = 0, src, parent[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            aGraph[i][j] = adj[i][j];
    while(bfs(s, t, aGraph, parent))
    {
        min_flow = INT_MAX;
        for(int i = t; i != s; i = parent[i])
        {
            src = parent[i];
            min_flow = min(min_flow, aGraph[src][i]);
        }
        for(int i = t; i != s; i = parent[i])
        {
            src = parent[i];
            aGraph[src][i] -= min_flow;
            aGraph[i][src] += min_flow;
        }
        maxFlow += min_flow;
    }
    return maxFlow;
}

int main()
{
    int Graph[n][n] = { 0, 16, 13, 0, 0, 0,
                        0, 0, 10, 12, 0, 0,
                        0, 4, 0, 0, 14, 0,
                        0, 0, 9, 0, 0, 20,
                        0, 0, 0, 7, 0, 4,
                        0, 0, 0, 0, 0, 0
                      };
    cout<<max_flow(0, 5, Graph)<<endl;
    return 0;
}
