#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void preorder(int arr[], int n)
{
    stack<int> s;
    int i = 0;
    while(1)
    {
        while(i < n)
        {
            printf("%d ", arr[i]);
            s.push(i);
            i = (i * 2) + 1;
        }
        if(s.empty())
            break;
        i = (s.top() * 2) + 2;
        s.pop();
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    preorder(arr, 7);
    return 0;
}
