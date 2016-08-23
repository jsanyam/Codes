#include<iostream>
#include<cmath>
using namespace std;

int *arr;
long long int *tree, *lazy;

void updateSumUtil(int si, int ss, int se, int p, int q, long long int diff)
{
    if(lazy[si])
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if(ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy [si];
        }
        lazy[si] = 0;
    }
    if(ss > se || se < p || ss > q)
        return;
    if(ss >= p && se <= q)
    {
        tree[si] += (se - ss + 1) * diff;
        if(ss != se)
        {
            lazy[si*2+1] += diff;
            lazy[si*2+2] += diff;
        }
        return;
    }
    int mid = ss + (se - ss) / 2;
    updateSumUtil(si*2+1, ss, mid, p, q, diff);
    updateSumUtil(si*2+2, mid+1, se, p, q, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void updateSum(int n, int p, int q, long long int diff)
{

    updateSumUtil(0, 0, n-1, p, q, diff);
}

long long int getSumUtil(int si, int ss, int se, int p, int q)
{
    if(lazy[si])
    {
        tree[si] += (se - ss + 1) * lazy[si];
        if(ss != se)
        {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy [si];
        }
        lazy[si] = 0;
    }

    if(ss > se || se < p || ss > q)
        return 0;

    if(ss >= p && se <= q)
        return tree[si];

    int mid = ss + (se - ss) / 2;
    return getSumUtil(si*2+1, ss, mid, p, q) + getSumUtil(si*2+2, mid+1, se, p, q);
}

long long int getSum(int n, int p, int q)
{
    return getSumUtil(0, 0, n-1, p, q);
}

void createSegTreeUtil(int si, int ss, int se)
{
    if(ss = se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = ss + (se - ss) / 2;
    createSegTreeUtil(si*2+1, ss, mid);
    createSegTreeUtil(si*2+2, mid+1, se);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void createSegTree(int n)
{
    int t_size = 2 * (int)pow(2, (int)ceil(log2(n))) - 1;
    tree = new long long int[t_size];
    lazy = new long long int[t_size];
    for(int i = 0; i<t_size; i++)
    {
        tree[i] = 0;
        lazy[i] = 0;
    }
    createSegTreeUtil(0, 0, n-1);
}

int main()
{
    int t, n, c, p, q, type;
    long long int v;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        arr = new int[n];
        for(int i = 0; i<n; i++)
            arr[i] = 0;
        createSegTree(n);
        while(c--)
        {
            cin>>type>>p>>q;
            if(type == 0)
            {
                cin>>v;
                updateSum(n, p-1, q-1, v);
            }
            else
                cout<<getSum(n, p-1, q-1)<<endl;
        }
    }
    return 0;
}
