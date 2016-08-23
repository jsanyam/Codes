#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long int arr[n], min = 1000000001;
        for(int  i = 0; i<n; i++)
            cin>>arr[i];
        sort(arr, arr+n);
        int end = k-1, start = 0;
        while(end != n)
        {
            if(arr[end]-arr[start]<min)
                min = arr[end] - arr[start];
            end++;
            start++;
        }
        cout<<min<<endl;
    }
    return 0;
}

//192.168.0.105
