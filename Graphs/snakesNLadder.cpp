#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int value, distance;
};

int snl(int last, int ladder[])
{
    queue<struct node> q;
    struct node vertex;
    int dist, val, visited[last];
    for(int j = 0; j< last; j++)
        visited[j] = 0;
    visited[0] = 1;
    q.push({0, 0});
    while(!q.empty())
    {
        vertex = q.front();
        if(vertex.value == last-1)
            break;
        q.pop();
        for(int i=1; i<=6 && (vertex.value+i)<last; i++)
        {
            if(visited[vertex.value+i] != 1)
            {
                visited[vertex.value+i]=1;
                dist = vertex.distance + 1;
                if(ladder[vertex.value+i] != -1)
                    val = ladder[vertex.value+i];
                    //q.push(vertex+i);
                else
                    val = vertex.value+i;
                    //q.push(vertex+i);
                q.push({val, dist});
            }
        }
    }
    return vertex.distance;
}

int main()
{
    int ladder[30];
    for(int j = 0; j < 30; j++)
        ladder[j] = -1;
    ladder[2] = 21;
    ladder[4] = 7;
    ladder[10] = 25;
    ladder[19] = 28;

    // Snakes
    ladder[26] = 0;
    ladder[20] = 8;
    ladder[16] = 3;
    ladder[18] = 6;
    cout<<snl(30, ladder);
    return 0;
}
