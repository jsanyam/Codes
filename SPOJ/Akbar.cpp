#include<iostream>
#include<queue>
#include<list>
#include<cstdio>
using namespace std;

struct node
{
    int val, level;
};

list<int> *graph;
int visited[1000000];

int check_soldier(int n, int root, int s)
{
    queue<node> q, clean;
    node temp;
    list<int>::iterator i;
    int temp_vis[n], lev = 0, flag = 0;
    for(int i = 0; i<n; i++)
        temp_vis[i] = 0;
    //cout<<"Hello"<<root<<endl;
    if(visited[root])
        return 0;
    else
    {
        q.push({root, lev});
        temp_vis[root] = 1;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp.level == s)
            {
            	//cout<<"Okay";
				//flag = 1;
				//temp_vis[temp.val] = 0;
                swap(q, clean);
                break;
            }
            //lev++;
            lev = temp.level + 1;
            for(i = graph[temp.val].begin(); i!=graph[temp.val].end(); i++)
            {
                if(!visited[*i])
                {
                    if(!temp_vis[*i])
                    {
                        q.push({*i, lev});
                        //visited[graph[temp.val][i]] = 1;
                        temp_vis[*i] = 1;
                    }
                }
                else
                {
                 	//cout<<root<<lev<<s;
                 	//cout<<lev;
                 	//cout<<graph[temp.val][i];
                    //cout<<"no"<<endl;
                    swap(q, clean);
                    return 0;
                }
            }
        }
        //visited[root] = 1;
		//flag = 1;
    }
	//cout<<flag<<endl;
    //if(flag == 	1)
        //cout<<"good"<<endl;
    for(int i = 0; i<n; i++)
    	if(temp_vis[i])
		{
    		visited[i] = temp_vis[i];
       		//cout<<i<<endl;
		}
    swap(q, clean);
	return 1;
    //cout<<"yeah"<<endl;
    //cout<<"yo"<<endl;
}

int main()
{
    int r, m;
    int t, a, b, k, s, i, n;
    scanf("%d", &t);
    //cin>>t;
    while(t--)
    {
        scanf("%d%d%d", &n, &r, &m);
        graph = new list<int>[n];
        //cin>>n>>r>>m;
        //cout<<n<<r<<m<<endl;
        //list<int> *graph;
        //graph = new list<int>[n];
        int flag = 0;
        for(i=0; i<n; i++)
            visited[i] = 0;
        for(i=0; i<r; i++)
        {
            scanf("%d%d", &a, &b);
            //cin>>a>>b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        //cout<<"m"<<m<<endl;
        for(i=0; i<m; i++)
        {
            scanf("%d%d", &k, &s);
            //cin>>k>>s;
            //cout<<k<<endl;
            if(!flag && !check_soldier(n, k-1, s))
            {
                //printf("No\n");
                //cout<<"No"<<endl;
                flag = 1;
                //break;
            }
        }
        if(flag == 1)
            printf("No\n");
        else
        {
            for(i = 0; i<n; i++)
                if(!visited[i])
                {
                    flag = 1;
                    printf("No\n");
                    break;
                }
            if(flag == 0)
                printf("Yes\n");
        }
            //cout<<"Yes"<<endl;
    }
    return 0;
}
