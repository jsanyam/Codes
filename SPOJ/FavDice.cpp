#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int t, i;
    float n, ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            ans += (1.00/i);
            //cout<<ans<<" ";
        }
        cout<<fixed<<setprecision(2);
        cout<<ans * n<<endl;
    }
    return 0;
}
