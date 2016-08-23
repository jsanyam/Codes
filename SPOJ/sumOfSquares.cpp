#include<iostream>
#include<cmath>
using namespace std;

int prime[1000001];

void sieve()
{
    for(int i=0; i<1000001; i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2; i<=sqrt(1000001); i++)
        if(prime[i])
            for(int j=i; i*j<=1000001; j++)
                prime[i*j] = 0;
}

int main()
{
    int c, plength = 0;
    long long int n;
    cin>>c;
    sieve();
    while(c--)
    {
        cin>>n;
        long long int count = 0;
        int flag = 0;
        for(int i = 2; i*i<=n; i++)
        {
            while(prime[i] && n%i == 0)
            {
                if(i%4 == 3)
                    count++;
                n /= i;
            }
            if(count%2 != 0)
            {
                flag = 1;
                break;
            }
            count = 0;
        }
        if(flag == 1)
            cout<<"No"<<endl;
        else if(n>1 && n%4 == 3)
            cout<<"No"<<endl;
        else if(flag == 0)
            cout<<"Yes"<<endl;
    }
    return 0;
}
