#include<iostream>
using namespace std;

int main()
{
    int t, n;
    long long int a[10000], sum, temp, start;
    cin>>t;
    while(t--)
    {
        sum = temp = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(i == 0)
                start = a[i];
            else
                sum += a[i] - start;
        }
        temp = sum;
        for(int i = 1; i < n - 1; i++)
        {
            temp -= (n - i) * (a[i] - a[i - 1]);
            sum += temp;
        }
        cout<<sum<<endl;
    }
    return 0;
}
