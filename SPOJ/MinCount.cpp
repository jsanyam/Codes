#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        cout<<n*(n+1)/6<<endl;   //(n*(n+1)/2)/3;
    }
    return 0;
}
