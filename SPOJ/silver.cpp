#include<iostream>
using namespace std;

int main()
{
    int n, k, i;
    cin>>n;
    while(n)
    {
        k = 1;
        i = 0;
        while(n>=k)
        {
            k = k * 2;
            i++;
        }
        cout<<i-1<<endl;
        cin>>n;
    }
    return 0;
}
