#include<iostream>
using namespace std;

struct data
{
    long long int occurences, digits;
};

int main()
{
    int t, n;
    struct data arr[50];
    arr[0] = {1, 1};
    for(int i = 2; i <= 50; i++)
    {
        arr[i - 1].occurences = arr[i- 2].occurences * 2;
        arr[i - 1].digits = (arr[i - 1].occurences / 2) * (i + 1);
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<arr[n - 1].occurences<<" "<<arr[n - 1].digits<<endl;
    }
    return 0;
}
