#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct node
{
    int first, second, measure;
};

int n, m;

void bfs(int *graph[], int *fGraph[], int first, int second)
{
    queue<node> q;
    q.push({first, second, 0});
    while(!q.empty())
    {
        node current = q.front();
        q.pop();
        int i = current.first;
        int j = current.second;
        if((j-1) >= 0 && graph[i][j-1] != 1 && fGraph[i][j-1] > current.measure + 1)
        {
            fGraph[i][j-1] = current.measure + 1;
            q.push({i, j-1, current.measure + 1});
        }
        if((j+1) < m && graph[i][j+1] != 1 && fGraph[i][j+1] > current.measure + 1)
        {
            fGraph[i][j+1] = current.measure + 1;
            q.push({i, j+1, current.measure + 1});
        }
        if((i-1) >= 0 && graph[i-1][j] != 1 && fGraph[i-1][j] > current.measure + 1)
        {
            fGraph[i-1][j] = current.measure + 1;
            q.push({i-1, j, current.measure + 1});
        }
        if((i+1) < n && graph[i+1][j] != 1 && fGraph[i+1][j] > current.measure + 1)
        {
            fGraph[i+1][j] = current.measure + 1;
            q.push({i+1, j, current.measure + 1});
        }
    }
}

int dist(int *graph[])
{
    int *fGraph[n];
    for(int i = 0; i<n; i++)
        fGraph[i] = new int[m];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        {
            if(graph[i][j] == 1)
                fGraph[i][j] = 0;
            else
                fGraph[i][j] = INT_MAX;
        }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        {
            if(graph[i][j] == 1)
                bfs(graph, fGraph, i, j);
        }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout<<fGraph[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int t;
    char a;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int *graph[n];
        for(int i = 0; i<n; i++)
            graph[i] = new int[m];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
            {
                cin>>a;
                graph[i][j] = a-48;
            }
        dist(graph);
    }
    return 0;
}
