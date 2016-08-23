#include<iostream>
using namespace std;

int main()
{
    int t;
    long long int n, ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n & 1)
            cout<<n / 2<<endl;
        else
        {
            ans = n / 2;
            if(n == 2)
                cout<<1<<endl;
            else if(ans & 1)
                cout<<ans - 2<<endl;
            else
                cout<<ans - 1<<endl;
        }
    }
    return 0;
}
