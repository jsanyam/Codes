#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct box
{
    long long int x1, x2, y1, y2;
};

struct Set
{
    int rank, parent;
};

int Find(struct Set *sets, int x)
{
    if(sets[x].parent != x)
        sets[x].parent = Find(sets, sets[x].parent);
    return sets[x].parent;
}

void Union(struct Set *sets, int xset, int yset)
{
    //int xset = Find(sets, x);
    //int yset = Find(sets, y);
    if(sets[xset].rank < sets[yset].rank)
    {
        sets[xset].parent = yset;
    }
    else if(sets[xset].rank > sets[yset].rank)
    {
        sets[yset].parent = xset;
    }
    else
    {
        sets[yset].parent = xset;
        sets[xset].rank++;
    }
}

int myComp(const void *a, const void *b)
{
    long long int l = ((struct box *)a)->y2;
    long long int r = ((struct box *)b)->y2;
    long long int x = r - l;
    if(x < 0)
        return -1;
    if(x > 0)
        return 1;
    if(x == 0)
    {
        long long int u = ((struct box *)a)->x1;
        long long int v = ((struct box *)b)->x1;
        long long int z = u - v;
        if(z < 0)
            return -1;
        if(z > 0)
            return 1;
        if(z == 0)
            return 0;
    }
}

int bin_search(struct box b[], int low, int mid, int high, struct box &ele)
{
    if(ele.y1 == b[mid].y2)
    {
        if(low == high)
            return low;
        if(ele.x2 <= b[mid].x1)
            high = mid - 1;
        else if(ele.x1 >= b[mid].x2)
            low = mid + 1;
        else
            high = mid;
    }
    else if(ele.y1 < b[mid].y2)
        low = mid + 1;
    else
        high = mid - 1;
    if(low > high)
        return -1;
    mid = low + (high - low) / 2;
        //cout<<"mid"<<mid<<endl;
    return bin_search(b, low, mid, high, ele);
}

int main()
{
    int n, xroot, yroot, mid, j, k;
    scanf("%d", &n);
    struct Set *sets = new struct Set[n];
    struct box *b= new struct box[n];
    for(int i = 0; i < n; i++)
        scanf("%lld%lld%lld%lld", &b[i].x1, &b[i].y1, &b[i].x2, &b[i].y2);
    qsort(b, n, sizeof(b[0]), myComp);
    for(int i = 0; i < n; i++)
    {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
    int count = n;
    for(int i = 0; i < n - 1; i++)
    {
        mid = (i + 1) + (n - i - 2) / 2;

        k = bin_search(b, i + 1, mid, n - 1, b[i]);
        for(j = k; k != -1 && j < n; j++)
        {
            xroot = Find(sets, i);
            yroot = Find(sets, j);
            if(b[i].y1 != b[j].y2 || b[i].x2 <= b[j].x1 || b[i].x1 >= b[j].x2)
                break;
            else if(xroot != yroot &&b[i].y1 == b[j].y2 && b[i].x2 > b[j].x1 && b[i].x1 < b[j].x2)
            {
                Union(sets, xroot, yroot);
                count--;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
