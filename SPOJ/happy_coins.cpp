#include<iostream>
using namespace std;

int main()
{
    int t, n, count;
    string s;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin>>n;
        while(n--)
        {
            cin>>s;
            if(s == "lxh")
                count++;
        }
        if(count % 2 == 0)
            cout<<"hhb"<<endl;
        else
            cout<<"lxh"<<endl;
    }
    return 0;
}
