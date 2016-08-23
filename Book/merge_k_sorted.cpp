// Incomplete Code

#include<cstdio>
#include<iostream>
using namespace std;

struct heap
{
    int *arr;
    int count;
    int size;
};

void percolate_down(struct heap *h, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, min = i;
    if(left < h->count && h->arr[left] <= h->arr[min])
        min = left;
    if(right < h->count && h->arr[right] < h->arr[min])
        min = right;
    if(min != i)
    {
        int temp = h->arr[i];
        h->arr[i] = h->arr[min];
        h->arr[min] = temp;
        percolate_down(h, min);
    }
}

void create_heap(int a[], struct heap *h, int n)
{
    for(int i = 0; i < n; i++)
        h->arr[h->count++] = a[i];
    for(int i = (h->count - 2) / 2; i >= 0; i--)
        percolate_down(h, i);
}

void insert_heap(struct heap *h, int data)
{
    //h->arr[count++] = data;
    h->count++;
    int i = h->count - 1;
    while(i > 0)
    {
        if(h->arr[(i - 1) / 2] > data)
        {
            h->arr[i] = h->arr[(i - 1) / 2];
            i = (i - 1) / 2;
        }
    }
    h->arr[i] = data;
}

int delete_heap(struct heap *h)
{
    int min = h->arr[0];
    h->arr[0] = h->arr[--h->count];
    percolate_down(h, 0);
    return min;
}

void merge_k_sorted()
{
    int a[] = {1, 5, 7}, b[] = {2, 4, 9}, c[] = {3, 6, 8};
    int  i = 1, j = 1, k = 1;
    struct heap *h = new struct heap;
    h->size = 3;
    h->count = 0;
    h->arr = new int[h->size];
    int arr[] = {a[0], b[0], c[0]}, final[9];
    create_heap(arr, h, 3);
    while( i != 3 || j != 3 || k != 3)
    {
        val = delete_heap(h);
        final[iter++] = val->first;
        if(val->second == 1)
            insert_heap(h, a[i++]);
        else if(val->second == 2)
            insert_heap(h, b[j++]);
        else
            insert_heap(h, c[k++]);
    }
}

int main()
{
    /*int a[] = {4, 2, 5, 6};
    struct heap *h = new struct heap;
    h->size = 10;
    h->count = 0;
    h->arr = new int[h->size];
    create_heap(a, h, 4);
    for(int i = 0; i < 5; i++)
        cout<<h->arr[i]<<" ";
    cout<<endl;
    insert_heap(h, 1);
    for(int i = 0; i < 5; i++)
        cout<<h->arr[i]<<" ";
    cout<<endl;*/
    merge_k_sorted();
    return 0;
}
