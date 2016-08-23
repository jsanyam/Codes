#include<iostream>
using namespace std;

int gcd(long long int a, long long int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    long long int t, a, b, q, hcf, temp;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>q;
        if(a > b)
        {
            temp = b;
            b = a;
            a = temp;
        }
        hcf = gcd(a, b);
        if(q <= b && q % hcf == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
