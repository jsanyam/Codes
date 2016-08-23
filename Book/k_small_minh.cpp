#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

struct heap
{
    int *arr;
    int size;
    int count;
};

void percolate_down(struct heap *h, int i)
{
    int left = i * 2 + 1, right = i  * 2 + 2;
    int min = i;
    if(left < (h)->count && (h)->arr[left] <= (h)->arr[min])
        min = left;
    if(right < (h)->count && (h)->arr[right] <= (h)->arr[min])
        min = right;
    if(min != i)
    {
        int temp = (h)->arr[min];
        (h)->arr[min] = (h)->arr[i];
        (h)->arr[i] = temp;
        percolate_down(h, min);
    }
}

//struct heap *
void build_heap(int a[], struct heap *h)
{
    if( h == NULL)
        return;
    for(int i = 0; i < h->size; i++)
    {
        h->arr[i] = a[i];
        h->count++;
    }
    for(int i = (h->count - 2) / 2; i >= 0; i--)
    {
        percolate_down(h, i);
    }
    //return h;
}

int Delete(struct heap *h)
{
    int temp = h->arr[0];
    h->arr[0] = h->arr[h->count - 1];
    h->count--;
    percolate_down(h, 0);
    return temp;
}

int k_smallest_ele(struct heap *h, int k)
{
    for(int i = 0; i < k - 1; i++)
        Delete(h);
    return Delete(h);
}

int main()
{
    int a[] = {5, 2, 8, 12, 3, 7, 1, 9};
    struct heap *h = new struct heap;
    h->count = 0;
    h->size = 8;
    h->arr = new int[h->size];
    build_heap(a, h);
    printf("%d\n", k_smallest_ele(h, 6));
    return 0;
}
