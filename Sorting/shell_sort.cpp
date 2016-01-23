#include<iostream>
using namespace std;

void shell_sort(int arr[], int arr_size)
{
    int i, j, k, temp;
    for(i=arr_size; i>0; i/=2)
    {
        for(j=i; j<arr_size; j++)
        {
            temp = arr[j];
            k=j-i;
            while(k>=0)
            {
                if(temp>=arr[k])
                    break;
                arr[k+i] = arr[k];
                k -= i;
            }
            arr[k+i] = temp;
        }
    }
}

void print_array(int arr[], int arr_size)
{
    for(int i = 0; i<arr_size; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};//15, 12, 16, 18, 5, 4, 1, 2, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    shell_sort(arr, arr_size);
    print_array(arr, arr_size);
    return 0;
}
