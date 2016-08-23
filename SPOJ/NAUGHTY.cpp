#include<iostream>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int first, second;
    long long int min, ans;
    map<int, long long int> ball, upface;
    map<int, long long int>::iterator iter, iter2;
    for(int i = 0; i < n; i++)
    {
        cin>>first>>second;
        ball[first]++;
        upface[first]++;
        if(first != second)
            ball[second]++;
    }
    for(iter = ball.begin(); iter != ball.end(); iter++)
    {
        if(iter->second < (n + 1) / 2)
        {
            ball.erase(iter);
            iter2 = upface.find(iter->first);
            if(iter2 != upface.end())
                upface.erase(iter2);
        }
    }
    if(ball.size() == 0)
        cout<<"Impossible"<<endl;
    else
    {
        iter2 = upface.begin();
        min = ((n + 1) / 2) - iter2->second;
        if(min <= 0)
            min = 0;
        iter2++;
        while(iter2 != upface.end())
        {
            ans = ((n + 1) / 2) - iter2->second;
            if(ans <= 0)
            {
                min = 0;
                break;
            }
            else if(ans < min)
                min = ans;
            iter2++;
        }
        cout<<min<<endl;
    }
    return 0;
}
