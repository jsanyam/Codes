#include<iostream>
using namespace std;

int main()
{
    string initial, objective;
    int value, count;
    while(1)
    {
        count = value = 0;
        cin>>initial>>objective;
        if(initial == "*")
            break;
        for(int i = 0; i < initial.length(); i++)
        {
            if(initial[i] != objective[i])
                value = 1;
            else
            {
                count += value;
                value = 0;
            }
        }
        count += value;
        cout<<count<<endl;
    }
    return 0;
}
