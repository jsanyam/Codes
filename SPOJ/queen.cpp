#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int row, column, dist;
};

int check_maze(char *a[], struct node start, struct node end, int m, int n)
{
    queue<struct node> q;
    struct node current;
    q.push(start);
    a[start.row][start.column] = 'X';
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current.row == end.row && current.column == end.column)
            return current.dist;
        else
        {
            for(int i = current.row - 1; i <= current.row + 1; i++)
                for(int j = current.column - 1; j <= current.column + 1; j++)
                    if(i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1 && a[i][j] == '.')
                    {
                        q.push({i, j, current.dist + 1});
                        a[i][j] = 'X';
                    }
            /*if(current.row - 1 >= 0 && a[current.row - 1][current.column] == '.')
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
            }*/
        }
    }
    return -1;
}

int main()
{
    int t, m, n;
    struct node start, end;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        char *a[m];
        for(int i = 0; i < m; i++)
            a[i] = new char[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                cin>>a[i][j];
                if(a[i][j] == 'S')
                {
                    start.row = i;
                    start.column = j;
                    start.dist = 0;
                    flag = 1;
                }
                else if(a[i][j] == 'F')
                {
                        end.row = i;
                        end.column = j;
                        end.dist = 0;
                }
            }
        cout<<check_maze(a, start, end, m, n)<<endl;
    }
    return 0;
}

