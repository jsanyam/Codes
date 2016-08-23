#include<iostream>
using namespace std;

int arr[1004][1003][3];

int func(int h, int a, int place)
{
    if(h <= 0 || a <= 0)
        return 0;
    if(arr[h][a][place])
        return arr[h][a][place];
    if(place == 0)
        arr[h][a][place] = 1 + max(func(h - 5, a - 10, 1), func(h - 20, a + 5, 2));
    else if(place == 1)
        arr[h][a][place] = 1 + max(func(h - 20, a + 5, 2), func(h + 3, a + 2, 0));
    else
        arr[h][a][place] = 1 + max(func(h - 5, a - 10, 1), func(h + 3, a + 2, 0));
    return arr[h][a][place];
}

int main()
{
    int t, h, a;
    cin>>t;
    while(t--)
    {
        cin>>h>>a;
        cout<<func(h+3, a + 2, 0)<<endl;
        //cout<<arr[h][a][2]<<endl;
    }
    return 0;
}
