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

int *find_span(int stock[], int no)
{
    int *span, p;
    span = new int[no];
    struct node *top = NULL;
    for(int i = 0; i < no; i++)
    {
        while(!isEmptyStack(&top) && stock[i] > stock[top->data])
            pop(&top);
        if(isEmptyStack(&top))
            p = -1;
        else
            p = top->data;
        span[i] = i - p;
        push(&top, i);
    }
    return span;
}

int main()
{
    int stock[] = {4, 3, 2, 1, 5};
    int no = (sizeof(stock)/sizeof(int));
    int *span = find_span(stock, no);
    for(int i = 0; i < no; i++)
        printf("%d ", span[i]);
    return 0;
}
