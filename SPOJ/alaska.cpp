#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, charging, flag;
    cin>>n;
    while(n != 0)
    {
        flag = 0;
        charging = 200;
        int station[n + 1];
        for(int i = 0; i < n; i++)
            cin>>station[i];
        station[n] = 1422;
        sort(station, station + n + 1);
        for(int i = 1; i < n; i++)
        {
            //cout<<station[i]<<endl;
            charging -= (station[i] - station[i - 1]);
            if(charging < 0)
            {
                flag = 1;
                break;
            }
            else if(charging < station[i + 1] - station[i])
                charging = 200;
            //else if(charging >= station[i + 1] - station[i])
            //    charging -= (station[i] - station[i - 1]);
        }
        if(flag == 1)
            cout<<"IMPOSSIBLE"<<endl;
        else
        {
            charging -= (station[n] - station[n - 1]);
            if(charging < 0)
                cout<<"IMPOSSIBLE"<<endl;
            else
            {
                for(int i = n - 1; i > 0; i--)
                {
                    charging -= (station[i + 1] - station[i]);
                    if(charging < 0)
                    {
                        flag = 1;
                        break;
                    }
                    else if(charging < station[i] - station[i - 1])
                        charging = 200;
                    //else if(charging >= station[i + 1] - station[i])
                        //    charging -= (station[i] - station[i - 1]);
                }
                if(flag == 1)
                    cout<<"IMPOSSIBLE"<<endl;
                else
                {
                    charging -= (station[1] - station[0]);
                    if(charging < 0)
                        cout<<"IMPOSSIBLE"<<endl;
                    else
                    cout<<"POSSIBLE"<<endl;
                }
            }
        }
        cin>>n;
    }
    return 0;
}
