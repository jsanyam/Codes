#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

struct queue
{
    int *arr;
    int size, front, rear;

};

struct queue *CreateQueue(int size)
{
    //struct queue *q = malloc(sizeof(struct queue));
    struct queue *q = new struct queue;
    if(!q)
    {
        printf("Queue Creation error");
        return NULL;
    }
    q->size = size;
    q->front = q->rear = -1;
    //q->arr = malloc(q->size * sizeof(int));
    q->arr = new int[q->size];
    if(!q->arr)
    {
        printf("Array Creation Error");
        return NULL;
    }
    return q;
}

int isQueueEmpty(struct queue *q)
{
    if(q->front == -1 && q->rear == -1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int data)
{
    if((q->rear + 1) % q->size == q->front)
        return;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
    if(q->front == -1)
        q->front = q->rear;
}

int dequeue(struct queue *q)
{
    if(q->rear == -1 && q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front];
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
    return data;
}

void alternate(struct queue *q)
{
    stack<int> s;
    for(int i = 0; i < (q->size / 2); i++)
        s.push(dequeue(q));
    for(int i = 0; i < (q->size / 2); i++)
    {
        enqueue(q, s.top());
        s.pop();
    }
    for(int i = 0; i < (q->size / 2); i++)
        enqueue(q, dequeue(q));
    for(int i = 0; i < (q->size / 2); i++)
        s.push(dequeue(q));
    for(int i = 0; i < (q->size / 2); i++)
    {
        enqueue(q, s.top());
        s.pop();
        enqueue(q, dequeue(q));
    }
    while(!isQueueEmpty(q))
        printf("%d ", dequeue(q));
}

int main()
{
    struct queue *q = CreateQueue(6);
    int data = dequeue(q);
    printf("%d\n", data);
    for(int i = 0; i < 6; i++)
        enqueue(q, i);
    alternate(q);
    return 0;
}
