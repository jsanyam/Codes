#include<cstdio>
#include<iostream>
using namespace std;

struct heap
{
    int *arr;
    int size;
    int count;
};

void percolate_down(struct heap **h, int i)
{
    int left = i * 2 + 1, right = i  * 2 + 2;
    int max = i;
    if(left < (*h)->count && (*h)->arr[left] >= (*h)->arr[max])
        max = left;
    if(right < (*h)->count && (*h)->arr[right] >= (*h)->arr[max])
        max = right;
    if(max != i)
    {
        int temp = (*h)->arr[max];
        (*h)->arr[max] = (*h)->arr[i];
        (*h)->arr[i] = temp;
        percolate_down(h, max);
    }
}

//struct heap *
void build_heap(int a[], struct heap *h, int size)
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
        percolate_down(&h, i);
    }
    //return h;
}

struct heap *heap_sort(int a[], struct heap *h, int n)
{
    h = new struct heap;
    h->size = n;
    h->count = 0;
    h->arr = new int[h->size];
    //h =
    build_heap(a, h, n);
    int count = h->count, temp;
    for(int i = 0; i < n; i++)
    {
        temp = h->arr[0];
        h->arr[0] = h->arr[h->count - 1];
        h->arr[h->count - 1] = temp;
        h->count--;
        percolate_down(&h, 0);
    }
    h->count = count;
    return h;
}

int main()
{
    int a[] = {5, 2, 4, 1, 7, 9, 3}, n = 7;
    struct heap *h = NULL;
    h = heap_sort(a, h, n);
    for(int i = 0; i < h->count; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
    return 0;
}
