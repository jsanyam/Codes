#include<iostream>
using namespace std;

long long int factor(long long int num)
{
    long long int i;
    for(i = 2; i * i <= num; i++)
        if(num % i == 0)
            return i;
    return -1;
}

int main()
{
    int t, n, ja, digit, flag = 0, iter = 0, inner = 0;
    long long int temp, mul[11], arr[11], final[11], pow = 1;
    cin>>t;
    while(t--)
    {
        iter++;
        cin>>n>>ja;
        cout<<"Case #"<<iter<<":"<<endl;
        for(long long int i = 0; i < n; i++)
            pow *= 2;
        cout<<pow<<endl;
        for(long long int i = pow / 2; i < pow; i++)
        {
            cout<<"yes"<<endl;
            mul[2] = 2, mul[3] = 3, mul[4] = 4, mul[5] = 5, mul[6] = 6, mul[7] = 7, mul[8] = 8, mul[9] = 9, mul[10] = 10;
            for(int i = 2; i < 11; i++)
                arr[i] = 1;
            temp = i;
            digit = temp & 1;
            if(!digit)
               continue;
            temp >>= 1;
            while(temp != 0)
            {
                digit = temp & 1;
                for(int j = 2; j < 11; j++)
                {
                    arr[j] += (digit * mul[j]);
                    mul[j] *= j;
                }
                temp >>= 1;
            }
            for(int j = 2; j < 11; j++)
            {
                flag = 0;
                //cout<<arr[j]<<" ";
                final[j] = factor(arr[j]);
                if(final[j] == -1)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag != 1)
            {
                inner++;
                cout<<arr[10]<<" ";
                for(int i = 2; i < 11; i++)
                    cout<<final[i]<<" ";
                cout<<endl;
            }
            if(inner == ja)
                break;
        }
    }
    return 0;
}
