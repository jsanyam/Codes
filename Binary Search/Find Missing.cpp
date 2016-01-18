#include<iostream>
using namespace std;

int searchNo(int arr[], int l, int h, int d)
{
    int mid = l + (h - l) / 2;
    cout<<arr[mid]<<endl;
    if(arr[mid]+d != arr[mid+1])
        return (arr[mid] + d);
    if(mid > 0 && arr[mid]-d != arr[mid-1])
        return (arr[mid] - d);
    if(arr[mid] > arr[0]+mid*d)
        return searchNo(arr, l, mid-1, d);
    return searchNo(arr, mid+1, h, d);
}

int missingNo(int arr[], int size)
{
    int d = arr[1] - arr[0];
    if(d > arr[2] - arr[1])
        d = arr[2] - arr[1];
    cout<<d<<endl;
    return searchNo(arr, 0, size-1, d);
}

int main()
{
    int arr[] = {2, 4, 8, 10, 12, 14, 16};
    int size = sizeof(arr)/sizeof(arr[0]); //can compute size here only not in functions
    cout<<missingNo(arr, size)<<endl;
    return 0;
}
