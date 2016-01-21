#include<iostream>
using namespace std;

int find_max(int arr[], int arr_size)
{
    int m = arr[0];
    for(int i = 0; i < arr_size; i++)
        if(arr[i] > m)
            m = arr[i];
    return m;
}

void radix_sort(int arr[], int arr_size)
{
    int pos[10], exp = 1, m = find_max(arr, arr_size);
    //cout<<m<<endl;
    int out[arr_size];
    while(1)
    {
        m = m/10;

        for(int i = 0; i < 10; i++)
            pos[i] = 0;

        for(int i = 0; i < arr_size; i++)
            pos[(arr[i]/exp)%10]++;

        for(int i = 1; i < 10; i++)
            pos[i] += pos[i-1];

        for(int i = arr_size-1; i >= 0; i--)
        {
            out[pos[(arr[i]/exp)%10]-1] = arr[i];
            pos[(arr[i]/exp)%10]--;
        }

        for(int i = 0; i < arr_size; i++)
        {
            arr[i] = out[i];
            //cout<<arr[i]<<endl;
        }

        if(m == 0)
            break;

        exp = exp * 10;
    }
}

int main()
{
    int arr[] = {588, 45, 548, 2, 125}; //{123, 225, 135, 546};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr, arr_size);
    for(int i = 0; i<arr_size; i++)
        cout<<arr[i]<<" ";
    return 0;
}
