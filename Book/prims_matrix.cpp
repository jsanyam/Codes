#include<cstdio>
#include<cstdlib>
#include<climits>
#include<iostream>
using namespace std;

int *dist, *mst_set, *parent;

void initialise_dist(int size)
{
    dist = new int[size];
    mst_set = new int[size];
    parent = new int[size];
    for(int i = 0; i < size; i++)
    {
        dist[i] = INT_MAX;
        mst_set[i] = 0;
    }
}

void primMST(int graph[5][5])
{
    int v = 5;
    initialise_dist(v);
    dist[0] = 0;
    parent[0] = -1;
    int min, min_index;
    for(int iter = 0; iter < (v - 1); iter++)
    {
        min = INT_MAX;
        for(int i = 0; i < v; i++)
            if(mst_set[i] != 1 && dist[i] < min)
            {
                min = dist[i];
                min_index = i;
            }
        mst_set[min_index] = 1;
        for(int i = 0; i < v; i++)
            if(mst_set[i] == 0 && graph[min_index][i] && dist[i] > graph[min_index][i])
            {
                    dist[i] = graph[min_index][i];
                    parent[i] = min_index;
            }
    }
    for(int i = 0; i < v; i++)
        printf("%d--->%d %d\n", parent[i], i, dist[i]);
}

int main()
{
    int graph[5][5]={{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0}
                    };
    primMST(graph);
    return 0;
}
