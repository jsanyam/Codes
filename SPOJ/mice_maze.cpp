#include<iostream>
#include<climits>
#include<list>
using namespace std;

struct node
{
    long long int cell, time;
};

struct grap
{
    long long int size;
    list<struct node> *l;
};

void initialise(long long int spt[], long long int dist[], long long int n)
{
    for(long long int i = 0; i < n; i++)
    {
        spt[i] = 0;
        dist[i] = INT_MAX;
    }
}

void update_spt(long long int dis, int index, struct grap g, long long int dist[], long long int spt[])
{
    //cout<<"fourth"<<index<<endl;
    spt[index] = 1;
    for(list<struct node>::iterator iter = g.l[index].begin(); iter != g.l[index].end(); iter++)
    {
        //cout<<"dist"<<dist[iter->cell]<<endl;
        if(spt[iter->cell] != 1 && dis + iter->time <= dist[iter->cell])
        {
            //cout<<"final"<<dis<<" "<<iter->time<<endl;
            dist[iter->cell] = dis + iter->time;
        }
    }
}

long long int return_mice(long long int n, long long int t, long long int dest, struct grap g)
{
    long long int ans = 0, i, j, k, min_dist, min_index, spt[n], dist[n];
    //for(i = 0; i < n; i++)
    //{
      //  if(i == dest)
        //    continue;
        //cout<<"first";
    initialise(spt, dist, n);
    //cout<<"second";
    //cout<<spt[0];
    dist[dest] = 0;
    for(k = 0; k < n-1; k++)
    {
        //cout<<"third";
        min_dist = INT_MAX;
        for(j = 0; j < n; j++)
            if(spt[j] != 1 && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        //cout<<min_dist;
        //if(min_index == dest)
          //  break;
        update_spt(min_dist, min_index, g, dist, spt);
    }
    for(i = 0; i < n; i++)
        if(dist[i] <= t)
        {
            ans += 1;
            //cout<<"Ans"<<ans<<endl;
        }
    return ans;
}

int main()
{
    long long int n, e, t, m, a, b, tim;
    cin>>n>>e>>t>>m;
    struct grap g;
    //cout<<"Hey";
    g.size = n;
    //cout<<"Hello";
    g.l = new list<struct node>[n];
    while(m--)
    {
        cin>>a>>b>>tim;
        g.l[b-1].push_back({a-1, tim});
    }
    cout<<return_mice(n, t, e - 1, g)<<endl;
    return 0;
}
