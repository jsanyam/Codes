#include<iostream>
#include<queue>
#include<climits>
using namespace std;

#define n 6

void MinCutMaxFlow(int Graph[n][n], int *rGraph[], int s);

int bfs(int *rGraph[], int parent[], int s, int t)
{
    queue<int> q;
    int visited[n];
    for(int i = 0; i<n; i++)
        visited[i] = 0;
    q.push(s);
    parent[s] = -1;
    visited[s] = 1;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i = 0; i<n; i++)
            if(visited[i] == 0 && rGraph[current][i]>0)
            {
                q.push(i);
                parent[i] = current;
                visited[i] = 1;
            }
    }
    return (visited[t] == 1);
}

void FordFulkerson(int Graph[n][n], int s, int t)
{
    int *rGraph[n], parent[n], flow=INT_MAX, max_flow=0;
    for(int i = 0; i<n; i++)
        rGraph[i] = new int[n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            rGraph[i][j] = Graph[i][j];
    while(bfs(rGraph, parent, s, t))
    {
        for(int j = t; j!=s; j=parent[j])
        {
            int i = parent[j];
            flow = min(flow, rGraph[i][j]);
        }
        for(int j = t; j!=s; j=parent[j])
        {
            int i = parent[j];
            rGraph[i][j] -= flow;
            rGraph[j][i] += flow;
        }
        max_flow += flow;
    }
    cout<<max_flow<<endl;
    MinCutMaxFlow(Graph, rGraph, s);
}

void MinCutMaxFlow(int Graph[n][n], int *rGraph[], int s)
{
    int visited[n], cut_flow = 0;
    for(int i = 0; i<n; i++)
        visited[i] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int i = 0; i<n; i++)
            if(visited[i] == 0 && rGraph[current][i] > 0)
            {
                q.push(i);
                visited[i] = 1;
            }
    }
    for(int i = 0; i<n; i++)
        if(visited[i] != 0)
            for(int j = 0; j<n; j++)
                if(visited[j] == 0 && Graph[i][j] > 0)
                {
                      cut_flow += Graph[i][j];
                      cout<<"{"<<i<<","<<j<<"}"<<endl;
                }
    cout<<cut_flow<<endl;
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
    FordFulkerson(Graph, 0, 5);
    return 0;
}
