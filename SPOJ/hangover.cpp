#include<iostream>
using namespace std;

int main()
{
    float a, sum, i;
    cin>>a;
    while(a != 0.00)
    {
        i = 1.00;
        sum = 0.00;
        while(sum<a)
        {
            i++;
            sum = sum+ (1/i);
        }
        cout<<i-1<<" card(s)"<<endl;
        cin>>a;
    }
    return 0;
}
