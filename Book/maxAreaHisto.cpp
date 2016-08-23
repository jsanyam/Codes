#include<cstdio>
#include<iostream>
#include<climits>
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

int maxAreaHisto(int arr[], int n)
{
    struct node *top = NULL;
    int max_area = INT_MIN, area, data;
    for(int i = 0; i <= n; i++)
    {
        while(!isEmptyStack(&top) && (i == n || arr[top->data] >= arr[i]))
        {
            data = pop(&top);
            if(isEmptyStack(&top))
                area = arr[data] * i;
            else
                area = arr[data] * (i - top->data - 1);
            if(area > max_area)
                max_area = area;
        }
        push(&top, i);
    }
    return max_area;
}

int main()
{
    int arr[] = {1, 2, 1, 4, 2};
    printf("Max Area in histogram is: %d\n", maxAreaHisto(arr, (sizeof(arr) / sizeof(int))));
    return 0;
}
