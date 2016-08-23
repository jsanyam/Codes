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

void pop_min(int data, struct node **top2)
{
    if(data == (*top2)->data)
        pop(top2);
}

void push_min(struct node **top1, struct node **top2)
{
    if(!(*top2) || (*top1)->data <= (*top2)->data)
        push(top2, (*top1)->data);
}

int get_min(struct node **top2)
{
    if(isEmptyStack(top2))
        return -1;
    return (*top2)->data;
}

int main()
{
    struct node *top1 = NULL, *top2 = NULL;
    push(&top1, 12);
    push_min(&top1, &top2);
    push(&top1, 2);
    push_min(&top1, &top2);
    push(&top1, 13);
    push_min(&top1, &top2);
    push(&top1, 1);
    push_min(&top1, &top2);
    printf("Top: %d\n", top1->data);
    int min = get_min(&top2);
    if(min != -1)
        printf("Min: %d\n", min);
    int data = pop(&top1);
    pop_min(data, &top2);
    printf("Top: %d\n", top1->data);
    min = get_min(&top2);
    if(min != -1)
        printf("Min: %d\n", min);
    return 0;
}
