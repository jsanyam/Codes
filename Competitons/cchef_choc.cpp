#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, i, j;
    long int n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%ld%ld", &n, &m);
        i = n & 1;
        j = m & 1;
        if(!i || !j)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
