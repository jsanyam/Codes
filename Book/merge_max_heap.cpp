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
void build_heap(int a[], struct heap *h, int n)
{
    if( h == NULL)
        return;
    for(int i = 0; i < n; i++)
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

void merge_heap(struct heap *h1, struct heap *h2)
{
    int initial = h1->count;
    for(int i = initial; i < initial + h2->count; i++)
    {
        h1->arr[i] = h2->arr[i - initial];
        h1->count++;
    }
    for(int i = h1->count / 2 - 1; i >= 0; i--)
        percolate_down(&h1, i);
}

int main()
{
    int a[] = {5, 2, 8, 12, 3, 7, 1, 9};
    int b[] = {19, 4, 2, 7, 3, 8};
    struct heap *h1 = new struct heap, *h2 = new struct heap;
    h1->count = 0;
    h1->size = 14;
    h1->arr = new int[h1->size];
    build_heap(a, h1, 8);
    h2->count = 0;
    h2->size = 6;
    h2->arr = new int[h2->size];
    build_heap(b, h2, 6);
    merge_heap(h1, h2);
    for(int i = 0; i < h1->count; i++)
        printf("%d ", h1->arr[i]);
    printf("\n");
    return 0;
}
