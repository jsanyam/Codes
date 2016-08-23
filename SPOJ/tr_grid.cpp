#include<iostream>
using namespace std;

int main()
{
    int t, row_odd, col_odd;
    long long int row, column;
    cin>>t;
    while(t--)
    {
        cin>>row>>column;
        row_odd = row & 1;
        col_odd = column & 1;
        if(row > column)
        {
            if(col_odd)
                cout<<'D'<<endl;
            else
                cout<<'U'<<endl;
        }
        else
        {
            if(row_odd)
                cout<<'R'<<endl;
            else
                cout<<'L'<<endl;
        }
    }
    return 0;
}
