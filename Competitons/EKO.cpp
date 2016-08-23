#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long int a[1000002], sum[1000002];

long long int max_height(long long int low, long long int high, long long int n, long long int m)
{
    long long int mid, sum_mid, sum_next;
    /*if(m == 0)
        return a[n];*/
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        sum_mid = sum[mid] - (a[mid] * (n - mid + 1));
        if(low == high)
            return ((sum_mid - m) / (n - low)) + a[low];
        if(m == sum_mid)
            return a[mid];
        else if(sum_mid > m)
        {
            sum_next = sum[mid + 1] - (a[mid + 1] * (n - mid));
            if(sum_next >= m)
                low = mid + 1;
            else
                return ((sum_mid - m) / (n - mid)) + a[mid];
        }
        else
            high = mid - 1;
    }
}

int main()
{
    long long int n, m, i;
    scanf("%lld%lld", &n, &m);
    a[0] = 0;
    for(i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a, a+n+1);
    sum[n] = a[n];
    for(i = n - 1; i >= 0; i--)
        sum[i] = sum[i + 1] + a[i];
    printf("%lld\n", max_height(0, n, n, m));
    return 0;
}
