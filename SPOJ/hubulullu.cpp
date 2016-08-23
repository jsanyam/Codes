#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int no;
        string arr[2] = {"Airborne wins.", "Pagfloyd wins."};
        int p;
        cin>>no>>p;
        cout<<arr[p]<<endl;
    }
    return 0;
}
