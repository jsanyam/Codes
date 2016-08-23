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

int max_ele(struct heap *h)
{
    int max= INT_MIN;
    for(int i = h->count / 2; i < h->count; i++)
        if(h->arr[i] > max)
            max = h->arr[i];
    return max;
}

int main()
{
    int a[] = {5, 2, 8, 12, 3, 7, 1, 9};
    struct heap *h = new struct heap;
    h->count = 0;
    h->size = 8;
    h->arr = new int[h->size];
    build_heap(a, h);
    printf("Max element is: %d\n", max_ele(h));
    return 0;
}
