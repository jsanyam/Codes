#include<iostream>
#include<cstdio>
using namespace std;

struct Stack
{
    long long int height;
    int index;
};

long long int maxArea(long long int a[], int n)
{
    long long int max_area = -1, current_area;
    int top = -1, left;
    struct Stack s[n];
    for(int i = 0; i <= n; i++)
    {
        while(top >= 0 && (i == n || s[top].height > a[i]))
        {
            if(top > 0)
                left = s[top - 1].index;
            else
                left = -1;
            current_area = (i - left - 1) * s[top].height;
            --top;
            if(current_area > max_area)
                max_area = current_area;
        }
        if(i < n)
        {
            ++top;
            s[top].height = a[i];
            s[top].index = i;
        }
    }
    return max_area;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        long long int a[n];
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        printf("%lld\n", maxArea(a, n));
        scanf("%d", &n);
    }
    return 0;
}
