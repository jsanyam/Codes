#include<iostream>
using namespace std;

int main()
{
    int t;
    long long int n, k, diff, ans, i;
    cin>>t;
    while(t--)
    {
        ans = 1;
        cin>>n>>k;
        diff = n - k;
        n = k + diff - 1;
        diff = diff<(n-diff)?diff:(n-diff);
        for(i = 1; i <= diff; i++)
        {
            ans = ans * (n--) / i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
