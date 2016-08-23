#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int myComp(int a, int b)
{
    return (b < a);
}

int main()
{
    int t, m, n, j = 1, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        int a[n];
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n, myComp);
        for(i = 0; i < n; i++)
        {
            if(m > 0)
                m -= a[i];
            else
                break;
        }
        printf("Scenario #%d:\n", j++);
        if(m <= 0)
            printf("%d\n", i);
        else
            printf("impossible\n");
    }
    return 0;
}
