#include<iostream>
#include<climits>
using namespace std;

int initialise(int spt[], int dist[], int parent[], int n)
{
    for(int i = 0; i < n; i++)
    {
        spt[i] = 0;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
}

void update_spt(int min_dist, int min_index, int n, int *graph[], int dist[], int spt[], int parent[])
{
    spt[min_index] = 1;
    for(int i = 0; i < n; i++)
        if(!spt[i] && graph[min_index][i] + min_dist <= dist[i])
        {
            dist[i] = graph[min_index][i] + min_dist;
            parent[i] = min_index;
            //cout<<parent[i]<<"parent"<<i<<endl;
        }
}

int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;

        int *graph[n], dist[n], spt[n], parent[n], min_index, min_dist;
        for(int i = 0; i < n; i++)
        {
            graph[i] = new int[n];
            for(int j = 0; j < n; j++)
                cin>>graph[i][j];
        }
        if(n == 1)
        {
            cout<<endl;
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            initialise(spt, dist, parent, n);
            dist[i] = 0;
            for(int j = 0; j < n - 1; j++)
            {
                min_dist = INT_MAX;
                for(int k = 0; k < n; k++)
                {
                    if(!spt[k] && dist[k] < min_dist)
                    {
                        min_dist = dist[k];
                        min_index = k;
                    }
                }
                //cout<<"min"<<min_index<<endl;
                update_spt(min_dist, min_index, n, graph, dist, spt, parent);
            }
            for(int l = i; l < n; l++)
            {
                if(i != l && dist[l] == graph[i][l] && parent[l] == i)
                    cout<<i + 1<<" "<<l + 1<<endl;
            }
            //cout<<"wohoo"<<endl;
        }
    }
    return 0;
}
