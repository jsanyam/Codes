#include<iostream>
#include<cstdio>
#include<stack>
#include<list>
#include<set>
using namespace std;

int *visited;

void insert_node(list<int> graph[], int src, int dest)
{
    graph[src].push_back(dest);
}

void DFS_Util(list<int> graph[], int node, stack<int> &s)
{
    visited[node] = 1;
    for(list<int>::iterator iter = graph[node].begin(); iter != graph[node].end(); iter++)
        if(!visited[*iter])
            DFS_Util(graph, *iter, s);
    s.push(node);
}

void reverse_graph(list<int> graph[], list<int> rev[], int n)
{
    for(int i = 0; i < n; i++)
        for(list<int>::iterator iter = graph[i].begin(); iter != graph[i].end(); iter++)
            insert_node(rev, *iter, i);
}

void DFS(list<int> rev[], int current, set<int> &myset)
{
    visited[current] = 1;
    //cout<<"c"<<current<<endl;
    myset.insert(current);
    for(list<int>::iterator iter = rev[current].begin(); iter != rev[current].end(); iter++)
        if(!visited[*iter])
            DFS(rev, *iter, myset);
}

void find_scc(list<int> rev[], stack<int> &s)
{
    set<int> myset;
    myset.insert(-1);
    while(!s.empty())
    {
        int current = s.top();
        s.pop();
        if(!visited[current])
        {
            myset.erase(myset.begin(), myset.end());
            DFS(rev, current, myset);
        }
    }
    printf("%d\n", myset.size());
    while(!myset.empty())
    {
        printf("%d ", *myset.begin() + 1);
        myset.erase(myset.begin());
    }
    printf("\n");
}

void all_reachable(list<int> graph[], int n)
{
    visited = new int[n];
    list<int> rev[n];
    stack<int> s;
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    for(int i = 0; i < n; i++)
        if(!visited[i])
            DFS_Util(graph, i, s);
    reverse_graph(graph, rev, n);
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    find_scc(rev, s);
}

int main()
{
    int n, m, src, dest;
    scanf("%d%d", &n, &m);
    list<int> graph[n];
    while(m--)
    {
        scanf("%d%d", &src, &dest);
        insert_node(graph, src-1, dest-1);
    }
    all_reachable(graph, n);
    return 0;
}
