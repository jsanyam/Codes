#include<iostream>
#include<algorithm>
using namespace std;

bool wayToSort(int i, int j)
{
    return (i > j);
}

int main()
{
    int t, n, m, d;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>d;
        int health[n];
        for(int i = 0; i<n; i++)
            cin>>health[i];
        sort(health, health+n, wayToSort);
        int i = 0, flag = 0;
        while(m > 0)
        {
            if(health[i] - d <= 0)
            {
                flag = 1;
                break;
            }
            health[i] -= d;
            m--;
            if(health[i] - d <= 0)
                i++;
        }
        if(flag == 1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
