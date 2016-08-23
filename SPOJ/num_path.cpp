#include<iostream>
using namespace std;

int main()
{
    int t, row, column;
    cin>>t;
    while(t--)
    {
        cin>>row>>column;
        int arr[row][column];
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
            {
                arr[i][j] = 0;
                if(i == 0 && j == 0)
                    arr[i][j] = 1;
                if(i - 1 >= 0)
                    arr[i][j] += arr[i-1][j];
                if(j - 1 >= 0)
                    arr[i][j] += arr[i][j - 1];
            }
        cout<<arr[row - 1][column - 1]<<endl;
    }
    return 0;
}
