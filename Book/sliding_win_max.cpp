#include<cstdio>
#include<iostream>
#include<deque>
using namespace std;

int *sliding_win_max(int a[], int w, int n)
{
    int *b = new int[n];
    int i;
    deque<int> dq;
    for(i = 0; i < w; i++)
    {
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    while(i < n)
    {
        b[i - w] = a[dq.front()];
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        if(!dq.empty() && dq.front() == (i - w))
            dq.pop_front();
        dq.push_back(i);
        i++;
    }
    b[n - w] = a[dq.front()];
    dq.clear();
    return b;
}

int main()
{
    int a[] = {11, -1, 3, 2, 4, 0, 1, 5};
    int *b = sliding_win_max(a, 3, 8);
    for(int i = 0; i < 6; i++)
        printf("%d ", b[i]);
    return 0;
}
