#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, c1 = 0, c2 = 0, c3 = 0, total = 1, temp;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s == "1/4")
            c1++;
        else if(s == "1/2")
            c2++;
        else
            c3++;
    }
    total += (c2)/2;
    total += c2%2;
    total += min(c1, c3);
    temp = c3 - c1;
    if(temp > 0)
        total += temp;
    else if(temp < -2)
        total += (abs(temp)+1)/4;
    cout<<total<<endl;
    return 0;
}
