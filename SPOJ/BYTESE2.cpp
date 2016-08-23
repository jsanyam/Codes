#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100], b[100];

int main()
{
    int t, n, count, j, max_count;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d%d", &a[i], &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        count = 1;
        j = 0;
        max_count = 0;
        for(int i = 0; i < n; i++)
        {
            count--;
            for(; j < n && a[j] < b[i]; j++)
                count++;
            if(count > max_count)
                max_count = count;
        }
        printf("%d\n", max_count);
    }
    return 0;
}
