#include<iostream>
using namespace std;

int main()
{
    int t, digits[10], iter = 0;
    long long int n;
    cin>>t;
    while(t--)
    {
        iter++;
        for(int i = 0; i < 10; i++)
            digits[i] = 0;
        cin>>n;
        if(n == 0)
        {
            cout<<"Case #"<<iter<<": "<<"INSOMNIA"<<endl;
            continue;
        }
        long long int temp = n, ans;
        int mul = 1, count = 0;
        while(1)
        {
            ans = temp;
            while(temp != 0)
            {
                digits[temp % 10] = 1;
                temp /= 10;
            }
            for(int i = 0; i < 10; i++)
                if(digits[i] == 1)
                    count++;
            if(count == 10)
                break;
            count = 0;
            mul++;
            temp = n * mul;
        }
        cout<<"Case #"<<iter<<": "<<ans<<endl;
    }
    return 0;
}
