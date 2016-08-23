#include<iostream>
#include<algorithm>
using namespace std;

int n;

long long int bin_search(long long int arr[], int first, int last, int sum)
{
    if(first > last || sum >= arr[last])
        return 0;
    int mid = first + (last - first) / 2;
    if(arr[mid] > sum && arr[mid - 1] <= sum)
        return (n - mid);
    if(arr[mid] > sum && arr[mid - 1] > sum)
        return bin_search(arr, first, mid-1, sum);
    if(arr[mid] <= sum)
        return bin_search(arr, mid+1, last, sum);
}

int main()
{
    int i, j;
    long long int sum, ans;
    cin>>n;
    while(n != 0)
    {
        long long int arr[n];
        sum = 0, ans = 0;
        for(i = 0; i < n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        for(i = 0; i < n-2; i++)
            for(j= i+1; j < n-1; j++)
            {
                sum = arr[i] + arr[j];
                ans += bin_search(arr, j+1, n-1, sum);
            }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}
