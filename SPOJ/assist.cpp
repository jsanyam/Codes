#include<iostream>
#include<stack>
using namespace std;

int arr[100001], primes[3000];

void seive()
{
    int i = 0;
    stack<string> s;
    string str, temp;
    cin>>str;
    cout<<str[0];
    while(1)
    {
        if(str[i] != ' ' || str[i] != '\0')
        {

            temp[i] = str[i];
            i++;
        }
        if(str[i] == ' ' || str[i] == '\0')
            break;
    }
    cout<<temp<<endl;
    int count = 0;
    for(int i = 0; i < 100001; i++)
        arr[i] = 1;
    for(int i = 2; i*i < 100001; i++)
        if(arr[i] == 1)
        {
            primes[count++] = i;
            cout<<i<<" ";
            if(count == 20)
                break;
            for(int j = i; i * j < 100001; j++)
                arr[i * j] = 0;
        }
    //for(int i = 0)
}


void func()
{
    int count = 0;
    for(int i = 0; i < 100001; i++)
        arr[i] = 1;
/*    for(int i = 2; )
        if(arr[i] == 1)
        {
            primes[count++] = i;
            cout<<i<<" ";
            if(count == 20)
                break;
            for(int j = i; i * j < 100001; j++)
                arr[i * j] = 0;
        }*/
    //for(int i = 0)
}

int main()
{
    seive();
    int n;
    cin>>n;
    while(n != 0)
    {
        cout<<primes[n-1]<<endl;
        cin>>n;
    }
    return 0;
}
