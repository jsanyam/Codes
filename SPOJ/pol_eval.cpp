#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, k, i, j, cas = 0;
    long long int ans = 0, exp;
    scanf("%d", &n);
    while(n != -1)
    {
        int c[n+1];
        for(i = 0; i < n+1; i++)
            scanf("%d", &c[i]);
        scanf("%d", &k);
        int x[k];
        for(i = 0; i < k; i++)
            scanf("%d", &x[i]);
        printf("Case %d:\n", ++cas);
        for(i = 0; i < k; i++)
        {
            exp = 1;
            ans = 0;
            ans += c[n];
            for(j = n-1; j >= 0; j--)
            {
                exp = exp * x[i];
                ans += exp * c[j];
            }
            printf("%lld\n", ans);
        }
        scanf("%d", &n);
    }
    return 0;
}
