#include<iostream>
using namespace std;

int main()
{
    int p, arr[40], ans[8];
    string s;
    cin>>p;
    while(p--)
    {
        int n;
        cin>>n;
        cin>>s;
        for(int i = 0; i<8; i++)
            ans[i] = 0;
        for(int i = 0; i<40; i++)
            if(s[i] == 'H')
                arr[i] = 1;
            else
                arr[i] = 0;
        for(int i = 0; i<38; i++)
            ans[arr[i]*4+arr[i+1]*2+arr[i+2]]++;
        cout<<n<<' ';
        for(int i = 0; i<8; i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}
