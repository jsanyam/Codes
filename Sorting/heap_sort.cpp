#include<iostream>
using namespace std;

void swap_nodes(int node, int min, int arr[])
{
    arr[node] += arr[min];
    arr[min] = arr[node] - arr[min];
    arr[node] -= arr[min];
}

void heapify(int arr[], int node, int arr_size)
{
    int min = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if(left < arr_size && arr[left] < arr[min])
        min = left;
    if(right < arr_size && arr[right] < arr[min])
        min = right;
    if(min == node)
        return;
    swap_nodes(node, min, arr);
    heapify(arr, min, arr_size);
}

void min_heap(int arr[], int arr_size)
{
    int j = arr_size-1;
    for(int i=(j-1)/2; i>=0; i--)
        heapify(arr, i, arr_size);
}

void heap_sort(int arr[], int arr_size)
{
    min_heap(arr, arr_size);
    while(1)
    {
        swap_nodes(0, arr_size-1, arr);
        arr_size--;
        if(arr_size == 1)
            break;
        heapify(arr, 0, arr_size);
    }
}

int main()
{
    int arr[] = {8, 5, 17, 4, 6, 9, 13};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr, arr_size);
    for(int i=0; i<arr_size; i++)
        cout<<arr[i]<<" ";
    return 0;
}
