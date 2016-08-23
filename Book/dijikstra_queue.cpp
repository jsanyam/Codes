#include<cstdio>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

struct graph
{
    int vertices, edges;
    list< pair<int, int> > *l;
};

typedef pair<int, int> ipair;

int *dist;

void initialise_dist(int size)
{
    dist = new int[size];
    for(int i = 0; i < size; i++)
        dist[i] = INT_MAX;
}

void insert_edge(struct graph *g, int source, int dest, int dis)
{
    g->l[source].push_back(make_pair(dest, dis));
    g->l[dest].push_back(make_pair(source, dis));
}

void dijkstra_queue(struct graph *g, int source)
{
    int current;
    priority_queue< ipair, vector<ipair>, greater<ipair> > q;
    initialise_dist(g->vertices);
    dist[source] = 0;
    q.push(make_pair(source, 0));
    while(!q.empty())
    {
        current = q.top().first;
        q.pop();
        for(list< pair<int ,int> >:: iterator iter = g->l[current].begin(); iter != g->l[current].end(); iter++)
            if(dist[current] + (*iter).second < dist[(*iter).first])
            {
                dist[(*iter).first] = dist[current] + (*iter).second;
                q.push(make_pair((*iter).first, dist[(*iter).first]));
            }
    }
    for(int i = 0; i < g->vertices; i++)
        printf("%d ", dist[i]);
    printf("\n");
}

int main()
{
    int source, dest, dis;
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->vertices = 9;
    g->edges = 14;
    g->l = new list< pair<int, int> >[g->vertices];
    for(int i = 0; i < g->edges; i++)
    {
        scanf("%d%d%d", &source, &dest, &dis);
        insert_edge(g, source, dest, dis);
    }
    dijkstra_queue(g, 0);
    return 0;
}
