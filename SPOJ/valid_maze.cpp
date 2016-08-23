#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int row, column;
};

string check_maze(char *a[], struct node start, struct node end, int m, int n)
{
    queue<struct node> q;
    struct node current;
    q.push(start);
    a[start.row][start.column] = '#';
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current.row == end.row && current.column == end.column)
            return "valid";
        else
        {
            if(current.row - 1 >= 0 && a[current.row - 1][current.column] == '.')
            {
                q.push({current.row - 1, current.column});
                a[current.row - 1][current.column] = '#';
            }
            if(current.row + 1 < m && a[current.row + 1][current.column] == '.')
            {
                q.push({current.row + 1, current.column});
                a[current.row + 1][current.column] = '#';
            }
            if(current.column - 1 >= 0 && a[current.row][current.column - 1] == '.')
            {
                q.push({current.row, current.column - 1});
                a[current.row][current.column - 1] = '#';
            }
            if(current.column + 1 < n && a[current.row][current.column + 1] == '.')
            {
                q.push({current.row, current.column + 1});
                a[current.row][current.column + 1] = '#';
            }
        }
    }
    return "invalid";
}

int main()
{
    int t, m, n, flag, count;
    struct node start, end;
    cin>>t;
    while(t--)
    {
        flag = count = 0;
        cin>>m>>n;
        char *a[m];
        for(int i = 0; i < m; i++)
            a[i] = new char[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                cin>>a[i][j];
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && a[i][j] == '.')
                {
                    if(!flag)
                    {
                        start.row = i;
                        start.column = j;
                        flag = 1;
                    }
                    else
                    {
                        end.row = i;
                        end.column = j;
                    }
                    count++;
                }
            }
        if(count == 2)
            cout<<check_maze(a, start, end, m, n)<<endl;
        else
            cout<<"invalid"<<endl;
    }
    return 0;
}
