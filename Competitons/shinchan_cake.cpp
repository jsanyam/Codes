#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, n, l, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &l, &b);
        for(int i = 0; i < n; i++)
        {
            if(l == 0 || b == 0)
                break;
            if(l > b)
            {
                l = l - b;
            }
            else
                b = b - l;
        }
        if(l == 0 || b == 0)
            printf("No\n");
        else
            printf("Yes %d\n", l * b);
    }
    return 0;
}
