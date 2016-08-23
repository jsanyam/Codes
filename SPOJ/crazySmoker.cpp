#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        int a;
        cin>>n;
        a = n%11;
        a = (a*8)%11;
        a = (1 + a + 10)%11;
        cout<<(11-a)%11<<endl;
    }
        return 0;
}
