#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long int n;
    while(t--)
    {
        cin>>n;
        if(n < 3)
            cout<<(n+1)/3<<endl;
        else
            cout<<(n+4)/3<<endl;
    }
    return 0;
}
