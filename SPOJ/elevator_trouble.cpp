#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int floor, step;
};

int *visited;

void min_steps(int f, int s, int g, int u, int d)
{
    int flr, stp, flag = 0;
    queue<node> q;
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty())
    {
        flr = q.front().floor;
        stp = q.front().step;
        //cout<<flr<<" "<<stp<<endl;
        q.pop();
        if(flr == g)
        {
            flag = 1;
            break;
        }
        if(flr + u <= f && !visited[flr + u])
        {
            q.push({flr + u, stp + 1});
            visited[flr + u] = 1;
        }
        if(flr - d > 0 && !visited[flr - d])
        {
            q.push({flr - d, stp + 1});
            visited[flr - d] = 1;
        }
    }
    if(flag == 1)
        cout<<stp<<endl;
    else
        cout<<"use the stairs"<<endl;
}

int main()
{
    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    visited = new int[f + 1];
    for(int i = 0; i <= f; i++)
        visited[i] = 0;
    min_steps(f, s, g, u, d);
    return 0;
}
