#include<iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(n <= 1 || (n&(n-1)) == 0)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;
    return 0;
}
