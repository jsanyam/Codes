#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        long long int n, ans;
        scanf("%lld", &n);
        ans = 2 + (n - 1) * 5 + (4 * (n-1) * (n-2)) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}
