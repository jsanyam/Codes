#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, val;
    long long int ans, left;
    while(1)
    {
        cin>>n;
        if(n == 0)
            break;
        //int arr[n];
        ans = left = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>val;
            ans += abs(left);
            left += val;
        }
        cout<<ans<<endl;
    }
    return 0;
}
