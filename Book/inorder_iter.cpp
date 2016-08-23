#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

void inorder(int arr[], int n)
{
    stack<int> s;
    int i = 0;
    while(1)
    {
        while(i < n)
        {
                s.push(i);
                i = (2 * i) + 1;
        }
        if(s.empty())
            break;
        i = s.top();
        s.pop();
        printf("%d ", arr[i]);
        i = 2 * i + 2;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    inorder(arr, 7);
    return 0;
}
