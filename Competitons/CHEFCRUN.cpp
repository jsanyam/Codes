#include<iostream>
#include<cstdio>
using namespace std;

struct semi
{
    long long int partial, total;
};

//int a[200002];
int *a;

long long int mini(long long int a, long long int b)
{
    if(a > b)
        return b;
    return a;
    //return (a>b?b:a);
}

int mod(int a, int n)
{
    if(a < 0)
    {
        a = -1 * a;
        return (n - (a % n));
    }
    return (a % n);
}

struct semi min_dist(int start, int end, int n)
{
    int i = mod(start - 1, n), j = end;
    long long int sum_b = 0, sum_f = 0, min_b = 0, min_f = 0, temp_b, temp_f;
    do
    {
        if(a[i] < 0)
        {
            sum_b += a[i];
            if(sum_b < min_b)
                min_b = sum_b;
            i = mod(i - 1, n);
        }
        else if(a[j] < 0)
        {
            sum_f += a[j];
            if(sum_f < min_f)
                min_f = sum_f;
            j = mod(j + 1, n);
        }
        else
        {
            temp_b = a[i] + sum_b;
            temp_f = a[j] + sum_f;
            if(temp_b < temp_f)
            {
                sum_b = temp_b;
                i = mod(i - 1, n);
            }
            else
            {
                sum_f = temp_f;
                j = mod(j + 1, n);
            }
        }
    }
    while(i != mod(j - 1, n));
    long long int partial = 2 * (min_b + min_f);
    long long int total = sum_b + sum_f;
    struct semi value;
    value.partial = partial;
    value.total = total;
    return value;
}

int main()
{
    int t, n, start, end;
    struct semi value_left, value_right;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        a = new int[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%d%d", &start, &end);
        value_left = min_dist(start - 1, end - 1, n);
        if(start == end)
            printf("%lld\n", value_left.partial);
        else
        {
            value_right = min_dist(end - 1, start - 1, n);
            long long int left = value_left.total + value_right.partial;
            long long int right = value_right.total + value_left.partial;
            printf("%lld\n", mini(left, right));
        }
    }
    return 0;
}
