#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int checkSuspicion(vector<int> arr[], int n)
{
    queue<int> q;
    int colour[n];
    for(int j = 0; j<n; j++)
    {
        for(int i = 0; i<n; i++)
            colour[i] = -1;
        q.push(j);
        colour[j] = 0;
        while(!q.empty())
        {
            int source = q.front();
            q.pop();
            for(int i=0; i<arr[source].size(); i++)
            {
                if(colour[arr[source][i]] == -1)
                {
                    colour[arr[source][i]] = 1 - colour[source];
                    q.push(arr[source][i]);
                }
                else if(colour[arr[source][i]] == colour[source])
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int t, cas = 1, a, b, n, inter;
    scanf("%d", &t);
    //int *arr[2001];
    //for(int  i=0; i<2001; i++)
        //arr[i] = (int)calloc(2001, sizeof(int));
        //arr[i] = new int[2001];
    while(t--)
    {
        scanf("%d%d", &n, &inter);
        vector<int> arr[n];
        /*for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                arr[i][j] = 0;*/
        while(inter--)
        {
            scanf("%d%d", &a, &b);
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
            //arr[a-1][b-1] = 1;
            //arr[b-1][a-1] = 1;
        }
        if(checkSuspicion(arr, n))
            printf("Scenario #%d:\nNo suspicious bugs found!\n", cas++);
        else
            printf("Scenario #%d:\nSuspicious bugs found!\n", cas++);
    }
    return 0;
}
