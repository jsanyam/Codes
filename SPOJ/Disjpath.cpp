#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<climits>
using namespace std;

int **flow_passed, *parent, **capacity;

void add_edge(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
    capacity[u][v] = 1;
}

int bfs(int start, int end, int n, vector<int> g[])
{
    int currentPathCapacity[n], current;
    //memset(parent, -1, sizeof(parent));
    //memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
    for(int i = 0; i < n; i++)
    {
        parent[i] = -1;
        currentPathCapacity[i] = 0;
    }
    queue<int> q;
    parent[start] = -2;
    currentPathCapacity[start] = INT_MAX;
    q.push(start);
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        for(int i = 0; i < g[current].size(); i++)
        {
            int to = g[current][i];
            if(parent[to] == -1)
            {
                if(capacity[current][to] - flow_passed[current][to] > 0)
                {
                    parent[to] = current;
                    currentPathCapacity[to] = min(currentPathCapacity[current], capacity[current][to] - flow_passed[current][to]);
                    if(to == end)
                        return currentPathCapacity[to];
                }
                q.push(to);
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<int> g[], stack<int> &st, int n)
{
    int min_flow, start = 0, end = 1, max_flow = 0;
    flow_passed = new int *[n];
    parent = new int[n];
    for(int i = 0; i < n; i++)
        flow_passed[i] = new int[n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            flow_passed[i][j] = 0;
    while(1)
    {
        min_flow = bfs(start, end, n, g);
        if(min_flow == 0)
            break;
        max_flow += min_flow;
        int current_node = end;
        st.push(-1);
        st.push(current_node);
        while(current_node != start)
        {
            int from = parent[current_node];
            flow_passed[from][current_node] += min_flow;
            flow_passed[current_node][from] -= min_flow;
            current_node = from;
            st.push(current_node);
        }
    }
    return max_flow;
}

int main()
{
    int k, n, j, node, iter = 1;
    scanf("%d%d", &k, &n);
    while(k != 0)
    {
        capacity = new int *[n];
        for(int i = 0; i < n; i++)
        {
            capacity[i] = new int[n];
            for(int l = 0; l < n; l++)
                capacity[i][l] = 0;
        }
        stack<int> st;
        vector<int> g[n];
        getchar();
        for(int i = 0; i < n; i++)
        {
            j = 0;
            char str[5002];
            scanf("%[^\n]%*c", str);
            while(1)
            {
                add_edge(g, i, (int)str[j] - 49);
                j++;
                if(str[j] == '\0')
                    break;
                j++;
            }
        }
        if(ford_fulkerson(g, st, n) == k)
        {
            printf("Case %d:\n", iter++);
            while(!st.empty())
            {
                node = st.top();
                st.pop();
                if(node == -1)
                    printf("\n");
                else
                    printf("%d ", node + 1);
            }
        }
        else
        {
            printf("Case %d:\nImpossible\n", iter++);
            stack<int> empty;
            swap(st, empty);
        }
        scanf("%d%d", &k, &n);
    }
    return 0;
}
