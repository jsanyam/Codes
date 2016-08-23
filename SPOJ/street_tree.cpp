#include<iostream>
using namespace std;

long long int hcf(long long int first, long long int second)
{
    /*if(second == 0)
        return first;
    if(first < second)
        return hcf(first, second % first);
    return hcf(second, first % second);*/ //General
    if(first < second)
        second = second % first;
    else
        first = first % second;
    if(first == 0)
        return second;
    else if(second == 0)
        return first;
    return hcf(first, second); //My Version
}

int main()
{
    int n;
    long long int x, a, d, prev;
    cin>>n;
    cin>>a;
    cin>>prev;
    cin>>x;
    d = hcf(prev - a, x - prev);
    prev = x;
    for(int i = 3; i < n; i++)
    {
        cin>>x;
        d = hcf(d, x - prev);
        prev = x;
    }
    //cout<<d<<endl;
    cout<<((x - a) / d + 1) - n<<endl;    //Xn = a + (n - 1)d
    return 0;
}
