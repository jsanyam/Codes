#include<iostream>
#include<cstdio>
#include<list>
#include<queue>
using namespace std;

void bfs(list<int> *l, int visited[], int source)
{
    queue<int> q;
    int current;
    q.push(source);
    visited[source] = 1;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        for(list<int>::iterator iter = l[current].begin(); iter != l[current].end(); iter++)
            if(!visited[*iter])
            {
                q.push(*iter);
                visited[*iter] = 1;
            }
    }
}

int main()
{
    int t, n, e, a, b, count;
    list<int> *l;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &e);
        l = new list<int>[n];
        int visited[n];
        count = 0;
        while(e--)
        {
            scanf("%d%d", &a, &b);
            l[a].push_back(b);
            l[b].push_back(a);
        }
        for(int i = 0; i < n; i++)
            visited[i] = 0;
        for(int i = 0; i < n; i++)
            if(visited[i] != 1)
            {
                bfs(l, visited, i);
                cout<<typeof(i);
                count++;
            }
        printf("%d\n", count);
    }
    return 0;
}
