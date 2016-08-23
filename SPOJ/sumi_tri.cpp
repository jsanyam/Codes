#include<iostream>
using namespace std;
int main()
{
    int t, n, sum, i, j, temp, a[100][100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
            for(j = 0; j <= i; j++)
                cin>>a[i][j];
        for(int i = 1; i < n; i++)
            for(j = 0; j <= i; j++)
            {
                temp = a[i][j];
                if(j <= i - 1)
                    a[i][j] += a[i-1][j];
                if(j - 1 >= 0 && temp + a[i-1][j-1] > a[i][j])
                    a[i][j] = temp + a[i - 1][j - 1];
            }
        sum = a[n - 1][0];
        for(j = 1; j < n; j++)
            if(a[n - 1][j] > sum)
                sum = a[n - 1][j];
        cout<<sum<<endl;
    }
    return 0;
}
