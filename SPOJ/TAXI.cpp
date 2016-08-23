#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct position
{
    int x, y;
};

struct position person[400];
int visited[400], bm[400];

bool mbm(vector<int> graph[], int index)
{
    for(int i = 0; i < graph[index].size(); i++)
    {
        if(!visited[graph[index][i]])
        {
            visited[graph[index][i]] = 1;
            if(bm[graph[index][i]] < 0 || mbm(graph, bm[graph[index][i]]))
            {
                bm[graph[index][i]] = index;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k, p, t, s, c, x, y;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d%d%d%d", &p, &t, &s, &c);
        vector<int> graph[t];
        int result = 0;
        memset(bm, -1, sizeof(bm));
        for(int i = 0; i < p; i++)
            scanf("%d%d", &person[i].x, &person[i].y);
        long int dis = (long int)s * c;
        for(int j = 0; j < t; j++)
        {
            memset(visited, 0, sizeof(visited));
            scanf("%d%d", &x, &y);
            for(int i = 0; i < p; i++)
            {
                if(dis >= (abs(person[i].x - x) + abs(person[i].y - y)) * 200)
                    graph[j].push_back(i);
            }
            if(mbm(graph, j))
                result++;
        }
        printf("%d\n", result);
    }
    return 0;
}
