#include<iostream>
using namespace std;

int main()
{
    long int sum1, sum2, sum;
    int n1, n2, i, j;
    while(true)
    {
        cin>>n1;
        if(n1 == 0)
            break;
        sum1 = sum2 = sum = 0;
        int arr1[n1];
        for(i = 0; i<n1; i++)
            cin>>arr1[i];
        cin>>n2;
        int arr2[n2];
        for(i = 0; i<n2; i++)
            cin>>arr2[i];
        i = j = 0;
        while(i < n1 && j < n2)
        {
            if(arr1[i] < arr2[j])
                sum1 += arr1[i++];
            else if(arr1[i] > arr2[j])
                sum2 += arr2[j++];
            else
            {
                sum1 += arr1[i++];
                sum2 += arr2[j++];
                sum += (sum1 > sum2?sum1:sum2);
                sum1 = sum2 = 0;
            }
        }
        while(i< n1)
            sum1 += arr1[i++];
        while(j < n2)
            sum2 += arr2[j++];
        sum += (sum1 > sum2?sum1:sum2);
        cout<<sum<<endl;
    }
    return 0;
}
