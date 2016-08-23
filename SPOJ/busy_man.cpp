#include<iostream>
#include<algorithm>
using namespace std;

struct time
{
    int start, end;
};

bool comp(struct time a, struct time b)
{
    return (a.end < b.end);
}

int main()
{
    int t, n, count, last;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin>>n;
        struct time act[n];
        for(int i = 0; i < n; i++)
            cin>>act[i].start>>act[i].end;
        sort(act, act+n, comp);
        count += 1;
        last = act[0].end;
        for(int i = 1; i < n; i++)
        {
            if(act[i].start >= last)
            {
                count++;
                last = act[i].end;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

