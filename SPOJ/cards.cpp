#include<iostream>
using namespace std;

int main()
{
    int t;
    long long int ans, n, mod = 1000007;
    cin>>t;
    while(t--)
    {
        cin>>n;
        //ans = ((n % mod * (n+1) % mod) % mod + (((n % mod * (n-1) % mod) % mod) / 2) % mod) % mod;// a/b mod n is wrong
        ans = ((n * (n+1)) + (n*(n-1)/2)) % 1000007<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
