#include<iostream>
using namespace std;

int mini(int a[], int i, int j)
{
    return a[i]<a[j]?i:j;
}

int WaterTrapped(int a[], int n)
{
    if(n == 1 || n == 2)
        return 0;
    int c = 1, i = 0, j = 2, k, total = 0, quant;
    while(c < n-1)
    {
        if(i<0 || j>n-1)
        {
            c++;
            i = c-1;
            j = c+1;
        }
        if(a[i] > a[c] && a[j] > a[c])
        {
            k = mini(a, i, j);
            for(int z = i+1; z<j; z++)
            {
                quant = a[k] - a[z];
                a[z] += quant;
                total += quant;
            }
            c = j;
            j = c+1;
        }
        if(a[i] <= a[c])
            i--;
        if(a[j] <= a[c])
            j++;
    }
    return total;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n; i++)
            cin>>a[i];
        cout<<WaterTrapped(a, n)<<endl;
    }
    return 0;
}
