#include<iostream>
using namespace std;

int main()
{
    int n, temp;
    long int no, ans = 0;
    cin>>n;
    while(n--)
    {
        cin>>no;
        ans = no & 1;
        if(ans == 1)
            cout<<no<<endl;
        else
        {
            ans >>= 1;
            while(no != 0)
            {
                ans *= 2;
                temp = no & 1;
                ans += temp;
                no >>= 1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
