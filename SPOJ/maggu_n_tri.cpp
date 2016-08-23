#include<iostream>
using namespace std;

int main()
{
    int t, temp;
    long long int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        temp = n & 1;
        if(temp)
        {
            if(((n+3)*(n+3))%48 >= 24)
                cout<<(((n+3)*(n+3))/48)+1<<endl;
            else
                cout<<((n+3)*(n+3))/48<<endl;
        }
        else
        {
            if((n * n)%48 >= 24)
                cout<<((n * n)/48)+1<<endl;
            else
                cout<<(n * n)/48<<endl;
        }
    }
    return 0;
}
