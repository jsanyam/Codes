#include<iostream>
#include<cstdio>
#include<list>
#include<queue>
using namespace std;

int visited[1000000];
int loc_visited[1000000];
list<int> *graph;

struct sol
{
    int city, power;
};

void insert_node(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

int bfs(struct sol &current, int &n)
{
    queue<struct sol> q, empty;
    int i = 0;
    while(i != n)
        loc_visited[i++] = 0;
    q.push({current.city, current.power});
    visited[current.city] = 1;
    loc_visited[current.city] = 1;
    //value--;
    while(!q.empty())
    {
        struct sol v = q.front();
        q.pop();
        if(v.power == 0)
            //swap(q, empty);
            break;
        v.power--;
        for(list<int>::iterator iter = graph[v.city].begin(); iter != graph[v.city].end(); iter++)
        {
            if(loc_visited[*iter])
                continue;
            else if(visited[*iter])
            {
                //swap(q, empty);
                return 0;
            }
            q.push({*iter, v.power});
            loc_visited[*iter] = 1;
            visited[*iter] = 1;
            //value--;
        }
    }
    return 1;
}

int main()
{
    int t, n, m, a, b;
    long int r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%ld%d", &n, &r, &m);
        struct sol strength;
        graph = new list<int>[n];
        for(long int i = 0; i < r; i++)
        {
            scanf("%d%d", &a, &b);
            insert_node(a - 1, b - 1);
        }
        for(int i = 0; i < n; i++)
            visited[i] = 0;
        //value = n;
        int flag = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &strength.city, &strength.power);
            strength.city--;
            if(flag == 0)
            {
                if(!visited[strength.city])
                {
                    if(!bfs(strength, n))
                        flag = 1;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        int i = 0;
        while(i != n)
        {
            if(!visited[i++])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
