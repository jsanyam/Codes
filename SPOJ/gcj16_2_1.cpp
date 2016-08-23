#include<iostream>
#include<algorithm>
using namespace std;

int comparator(int i, int j)
{
    return i > j;
}

int main()
{
    int t, iter = 1;
    cin>>t;
    string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    while(t--)
    {
        string s;
        cin>>s;
        int arr[s.length()];
        int x = s.find("E");
        cout<<x;
        //s.erase(x, x+1);
        //for(int i = 0; i < 9; i += 2)
        //{

        //}
        cout<<"Case #"<<iter<<": "<<s<<endl;
        iter++;
    }
}
