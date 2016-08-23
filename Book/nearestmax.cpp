#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int isEmptyStack(struct node **top)
{
    if(!*top)
        return 1;
    return 0;
}

void push(struct node **top, int data)
{
    struct node *temp;
    temp = new struct node;
    if(!temp)
    {
        printf("Cannot push as no memory left");
        return;
    }
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int pop(struct node **top)
{
    if(isEmptyStack(top))
    {
        printf("Cannot pop as Stack is empty");
        return -1;
    }
    struct node *temp = *top;
    *top = (*top)->next;
    //printf("%d", temp->data);
    return temp->data;
}

int *nearest_max(int arr[], int n)
{
    int *max_arr = new int[n];
    struct node *top = NULL;
    for(int i = n-1; i >= 0; i--)
    {
        while(!isEmptyStack(&top) && top->data <= arr[i])
            pop(&top);
        if(isEmptyStack(&top))
            max_arr[i] = -1;
        else
            max_arr[i] = top->data;
        push(&top, arr[i]);
    }
    return max_arr;
}

int main()
{
    int arr[] = {12, 7, 9, 8, 9, 10};
    int n = (sizeof(arr)/sizeof(int));
    int * max_arr = nearest_max(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", max_arr[i]);
    return 0;
}
