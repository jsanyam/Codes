#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
#include<list>
#include<map>
using namespace std;
#define MAX 1000000001

struct node
{
    int ngh;
    long long int dis;
};

struct comparator
{
    bool operator()(struct node i, struct node j)
    {
        return i.dis > j.dis;
    }
};

void update_neighs(struct node current, list<struct node> *graph, int spt[], long long int dist[], priority_queue<struct node, std::vector<struct node>, comparator> &minHeap)
{
    spt[current.ngh] = 1;
    for(list<struct node>::iterator iter = graph[current.ngh].begin(); iter != graph[current.ngh].end(); iter++){
        //cout<<"hey"<<endl;
        //cout<<iter->dis<<endl;
        //cout<<"yeah"<<iter->ngh<<endl;
        if(spt[iter->ngh] != 1 && dist[current.ngh] + iter->dis <= dist[iter->ngh])
        {
            //cout<<iter->dis<<"yo"<<endl;
            dist[iter->ngh] = dist[current.ngh] + iter->dis;
            minHeap.push({iter->ngh, dist[iter->ngh]});
        }
    }
}

long long int shpath(list<struct node> *graph, int src, int dest, int n)
{
    priority_queue<struct node, std::vector<struct node>, comparator> minHeap;
    int spt[n];
    long long int dist[n];
    struct node current;
    for(int i = 0; i < n; i++)
    {
        spt[i] = 0;
        dist[n] = MAX;
        //if(i == src)
            //minHeap.push({src, 0});
        //else
          //  minHeap.push({i, INT_MAX});
    }
    dist[src] = 0;
    minHeap.push({src, 0});
    while(!minHeap.empty())
    {
        current = minHeap.top();
        //cout<<current.ngh;
        minHeap.pop();
        if(current.ngh == dest)
            break;
        else if(spt[current.ngh] == 1)
            continue;
        update_neighs(current, graph, spt, dist, minHeap);
    }
    return current.dis;
}

int main()
{
    int s, n, p, neigh, r, src, dest;
    long long int dist;
    char city_name[15], source[15], destination[15];
    list<struct node> *graph;
    scanf("%d", &s);
    while(s--)
    {
        scanf("%d", &n);
        graph = new list<struct node>[n];
        map<string, int> city;
        for(int i = 0; i < n; i++)
        {
            //cin>>city_name;
            //gets(city_name);
            scanf("%s", city_name);
            city[city_name] = i;
            scanf("%d", &p);
            while(p--)
            {
                scanf("%d%lld", &neigh, &dist);
                graph[i].push_back({neigh - 1, dist});
            }
        }
        scanf("%d", &r);
        while(r--)
        {
            //cin>>source>>destination;
            //gets(source);
            //gets(destination);
            scanf("%s%s", source, destination);
            src = city[source];
            dest = city[destination];
            printf("%lld\n", shpath(graph, src, dest, n));
        }
    }
    return 0;
}
