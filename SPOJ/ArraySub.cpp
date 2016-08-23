#include<iostream>
#include<deque>
using namespace std;

int *arr;

void printMaxWindow(int n, int k)
{
    deque<int> q(k);
    int i;
    for(i = 0; i<k; i++)
    {
        while(!q.empty() && arr[i]>arr[q.back()])
                    q.pop_back();
        q.push_back(i);
    }
    cout<<arr[q.front()]<<" ";
    int j = 0;
    for(; i<n; i++)
    {
        if(q.front() == j)
                    q.pop_front();
        while(!q.empty() && arr[i] > arr[q.back()])
            q.pop_back();
        q.push_back(i);
        j++;
        cout<<arr[q.front()]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, k;
    cin>>n;
    arr = new int[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    cin>>k;
    printMaxWindow(n, k);
    return 0;
}
