#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n != 0)
    {
        int a[n], flag = 0;
        for(int i = 0; i<n; i++)
            cin>>a[i];
        for(int i = 0; i<n; i++)
            if(a[a[i] - 1] != i+1)
            {
                flag = 1;
                break;
            }
        if(flag == 1)
            cout<<"not ambiguous"<<endl;
        else
            cout<<"ambiguous"<<endl;
        cin>>n;
    }
    return 0;
}
