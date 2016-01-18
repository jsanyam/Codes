#include<iostream>
using namespace std;
int merge(int a[], int b[], int m, int n)
{
    int y, i=0, j=0, k=-1, flag=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            y=a[i];
            k++;
            i++;
        }
        else if(a[i]>b[j])
        {
            y=b[j];
            k++;
            j++;
        }
        if(a[i]==b[j])
        {
            flag=1;
            break;
        }
    }
    while(i<m-1 && flag==0)
    {
        y=a[i];
        k++;
        i++;
        if(a[i]==a[i+1])
        {
            flag=1;
            break;
        }
    }
    while(j<n-1 && flag==0)
    {
        y=b[j];
        k++;
        j++;
        if(b[j]==b[j+1])
        {
            flag=1;
            break;
        }
    }
    return y;
}
mergesort(int arr[], int low, int high)
int main()
{
    int m, n;
    cin>>m>>n;
    int a[m], b[n];
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    int mid=merge(a, b, m, n);
    cout<<mid;
}


