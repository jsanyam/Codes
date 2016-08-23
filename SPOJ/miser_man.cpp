#include<iostream>
#include<cstdio>
using namespace std;

int n, m;

int fare(int *arr[], int i, int j, int *min_cost[])
{
    if(j < 0 || j > m-1)
        return 10001;
    if(i == n-1)
        return arr[i][j];
    if(min_cost[i][j] > 0)
        return min_cost[i][j];
    min_cost[i][j] = arr[i][j] + min(min(fare(arr, i+1, j+1, min_cost), fare(arr, i+1, j-1, min_cost)), fare(arr, i+1, j, min_cost));
    return min_cost[i][j];
}

int main()
{
    scanf("%d%d", &n, &m);
    int *arr[n], *min_cost[n], min_fare = 10001;
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        min_cost[i] = new int[m];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            min_cost[i][j] = 0;
        }
    for(int j = 0; j<m; j++)
    {
        min_cost[0][j] = fare(arr, 0, j, min_cost);
        //cout<<min_cost[0][j]<<" ";
        if(min_cost[0][j] < min_fare)
            min_fare = min_cost[0][j];
    }
    printf("%d", min_fare);
    return 0;
}
