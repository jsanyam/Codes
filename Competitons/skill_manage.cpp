#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct course
{
    int time, job;
};

int myComp(const void *a, const void *b)
{
    int l = ((struct course *)a)->job;
    int r = ((struct course *)b)->job;
    int x = r - l;
    if(x < 0)
        return -1;
    if(x > 0)
        return 1;
    if(x == 0)
    {
        int u = ((struct course *)a)->time;
        int v = ((struct course *)b)->time;
        int z = u - v;
        if(z < 0)
            return -1;
        if(z > 0)
            return 1;
        if(z == 0)
            return 0;
    }
}

long long int knapSack(long long int W, struct course c[], int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(W < c[n - 1].time)
        return knapSack(W, c, n - 1);
    else
        return max(c[n- 1].job + knapSack(W - c[n-1].time, c, n - 1), knapSack(W, c, n - 1));
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        struct course c[n];
        long long int stu[m], s;
        for(int i = 0; i < n; i++)
            scanf("%d%d", &c[i].time, &c[i].job);
        //qsort(c, n, sizeof(c[0]), myComp);
        for(int j = 0; j < m; j++)
        {
            stu[j] = 0;
            scanf("%lld", &s);
            stu[j] = knapSack(s, c, n);
        }
        for(int i = 0; i < m; i++)
            printf("%lld ", stu[i]);
        printf("\n");
    }
    return 0;
}
