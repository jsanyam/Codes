#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

long int visited[100000];

long int magic(long int a[], long int index, long int n)
{
    long int count = 1;
    map<int, int> seen;
    while(1)
    {
        if(visited[index])
        {
            if(seen[index] > 0)
                return (count - seen[index]);
            return 0;
        }
        visited[index] = 1;
        seen[index] = count++;
        index = a[index];
    }
    return 0;
}

int main()
{
    int t;
    long int temp, n, a[100000], sum, i;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%ld", &n);
        for(i = 0; i < n; i++)
        {
            visited[i] = 0;
            scanf("%ld", &temp);
            long int x = (i + 1);
            a[i] = (x + temp) % n;
        }
        for(i = 0; i < n; i++)
        {
            if(!visited[i])
                sum += magic(a, i, n);
        }
        printf("%ld\n", sum);
    }
    return 0;
}
