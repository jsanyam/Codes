#include<iostream>
using namespace std;

int mod(int a, int m)
{
    int b = a%m;
    if(b<0)
        b += m;
    return b;
}

int main()
{
    int a = -5;
    int b = -3;
    cout<<mod((mod(a, 5)-mod(b, 5)), 5)<<endl;
    return 0;
}
