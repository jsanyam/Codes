#include<iostream>
#include<climits>
#include<list>
using namespace std;

void initialise(long long int spt[], long long int dist[], long long int n)
{
    for(long long int i = 0; i < 501; i++)
    {
        spt[i] = 0;
        dist[i] = INT_MAX;
    }
}

void update_spt(long long int dis, long long int index, long long int *g[], long long int dist[], long long int spt[], long long int n)
{
    spt[index] = 1;
    for(long long int i = 0; i < 501; i++)
        if(spt[i] != 1 && dis + g[index][i] < dist[i])
        {
            dist[i] = dis + g[index][i];
            //cout<<"i"<<dist[i]<<endl;
        }
}

void solve_queries(long long int n, long long int source, long long int *g[])
{
    long long int i, j, k, min_dist, min_index, spt[501], dist[501], q, dest;
    initialise(spt, dist, n);
    dist[source] = 0;
    for(k = 0; k < 500; k++)
    {
        min_dist = INT_MAX;
        for(j = 0; j < 501; j++)
            if(spt[j] != 1 && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        update_spt(min_dist, min_index, g, dist, spt, n);
    }
    cin>>q;
    for(i = 0; i < q; i++)
    {
        cin>>dest;
        if(dist[dest] < INT_MAX)
            cout<<dist[dest]<<endl;
        else
            cout<<"NO PATH"<<endl;
    }
}

int main()
{
    long long int n, m, a, b, w, u, temp = INT_MAX;
    //cout<<temp+50000<<endl;
    cin>>n;
    long long int *g[501];
    for(long long int i = 0; i < 501; i++)
        g[i] = new long long int[501];
    for(long long int i = 0; i < 501; i++)
        for(long long int j = 0; j < 501; j++)
            g[i][j] = INT_MAX;
    m = n;
    while(m--)
    {
        cin>>a>>b>>w;
        if(w < g[a][b])
        {
            g[a][b] = w;
            g[b][a] = w;
        }
     }
    cin>>u;
    solve_queries(n + 1, u, g);
    return 0;
}
