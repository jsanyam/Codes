#include<iostream>
#include<algorithm>
using namespace std;

int comparator(int i, int j)
{
    return i > j;
}

int main()
{
    int t, n, m, current, iter, count;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr[n], sorted[n];
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted, sorted + n, comparator);
        count = current = iter = 0;
        while(1)
        {
            if(sorted[current] == arr[iter])
            {
                if(iter == m)
                    break;
                count += 1;
                current++;
                iter = (iter + 1) % n;
            }
            else
                iter = (iter + 1) % n;
        }
        cout<<count + 1<<endl;
    }
    return 0;
}
