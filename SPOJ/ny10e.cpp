#include<iostream>
using namespace std;

long long int final[64], temp[10];

void non_decre()
{
    int i,  k, loop = 62;
    long long int current;
    final[0] = 10;
    current = final[0];
    final[1] = 0;
    for(i = 0; i < 10; i++)
    {
        temp[i] = current - i;
        final[1] += temp[i];
    }
    k = 2;
    while(loop--)
    {
        current = final[k-1];
        final[k] = 0;
        for(i = 0; i < 10; i++)
        {
            final[k] += current;
            current -= temp[i];
            temp[i] += current;
        }
        //for(i = 0; i < 10; i++)
          //  cout<<temp[i]<<" ";
        //cout<<endl<<k<<" "<<final[k]<<endl;
        k++;
    }
}

int main()
{
    int t, a, n;
    cin>>t;
    non_decre();
    while(t--)
    {
        cin>>a>>n;
        cout<<a<<" "<<final[n-1]<<endl;
    }
    return 0;
}
