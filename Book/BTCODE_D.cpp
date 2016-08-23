#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int m, n, t;
    long long int profit_i, profit, c;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        int a[m][n], b[m][n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &b[i][j]);
        profit = 0;
        for(int i = 0; i < m; i++)
        {
            profit_i = 0;
            for(int j = 0; j < n; j++)
            {
                scanf("%lld", &c);
                profit_i = max(profit_i, c * min(a[i][j], b[i][j]));
            }
            profit += profit_i;
        }
        printf("%lld\n", profit);
    }
    return 0;
}
