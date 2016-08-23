#include<iostream>
#include<climits>
#include<queue>
using namespace std;

struct node
{
    int i, j, dist;
};

struct comparator
{
    bool operator()(struct node i, struct node j)
    {
        return i.dist > j.dist;
    }
};

int main()
{
    int w, h;
    struct node start, dest, current;
    while(1)
    {
        cin>>h>>w;
        if(w == 0)
            break;
        int graph[w][h];
        char temp;
        int dist[w][h], spt[w][h];
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
            {
                dist[i][j] = INT_MAX;
                spt[i][j] = 0;
                cin>>temp;//graph[i][j];
                if(temp == 'S')
                {
                    graph[i][j] = 0;
                    dist[i][j] = 0;
                    start = {i, j, 0};
                }
                else if(temp == 'D')
                {
                    graph[i][j] = 0;
                    dest = {i, j, 0};
                    //cout<<i<<" "<<j<<endl;
                }
                else if(temp == 'X')
                    spt[i][j] = 1;
                else
                    graph[i][j] = temp - 48;
            }
        priority_queue<struct node, std::vector<struct node>, comparator> minHeap;
        minHeap.push(start);
        while(!minHeap.empty())
        {
            current = minHeap.top();
            minHeap.pop();
            if(spt[current.i][current.j] == 1)
                continue;
            else if(current.i == dest.i && current.j == dest.j)
                break;
            spt[current.i][current.j] = 1;
            if(!spt[current.i - 1][current.j] && current.i - 1 >= 0 && dist[current.i][current.j] + graph[current.i - 1][current.j] <= dist[current.i - 1][current.j])
            {
                dist[current.i - 1][current.j] = dist[current.i][current.j] + graph[current.i - 1][current.j];
                minHeap.push({current.i - 1, current.j, dist[current.i - 1][current.j]});
            }
            if(!spt[current.i + 1][current.j] && current.i + 1 < w && dist[current.i][current.j] + graph[current.i + 1][current.j] <= dist[current.i + 1][current.j])
            {
                dist[current.i + 1][current.j] = dist[current.i][current.j] + graph[current.i + 1][current.j];
                minHeap.push({current.i + 1, current.j, dist[current.i + 1][current.j]});
            }
            if(!spt[current.i][current.j - 1] && current.j - 1 >= 0 && dist[current.i][current.j] + graph[current.i][current.j - 1] <= dist[current.i][current.j - 1])
            {
                dist[current.i][current.j - 1] = dist[current.i][current.j] + graph[current.i][current.j - 1];
                minHeap.push({current.i, current.j - 1, dist[current.i][current.j - 1]});
            }
            if(!spt[current.i][current.j + 1] && current.j + 1 < h && dist[current.i][current.j] + graph[current.i][current.j + 1] <= dist[current.i][current.j + 1])
            {
                dist[current.i][current.j + 1] = dist[current.i][current.j] + graph[current.i][current.j + 1];
                minHeap.push({current.i, current.j + 1, dist[current.i][current.j + 1]});
            }
        }
        cout<<dist[dest.i][dest.j]<<endl;
    }
    return 0;
}
