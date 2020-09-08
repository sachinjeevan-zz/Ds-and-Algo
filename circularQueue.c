#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *q;
    int size;
    int front;
    int rear;
};
struct queue* circularQueueInit(int n)
{
    struct queue* x = (struct queue*)malloc(sizeof(struct queue));
    x->size = n;
    x->q = (int*)malloc(sizeof(int)*x->size);
    x->front = x->rear = 0;
    return x;

}
int isFull(struct queue* x)
{
    if((x->rear+1)%x->size == x->front)
        return 1;
    return 0;
}
int isEmpty(struct queue* x)
{
    if(x->front == x->rear)
        return 1;
    return 0;
}
void enqueue(struct queue* x,int ele)
{
    if(isFull(x)==1)
        printf("Queue is full");
    else
    {
        x->rear = (x->rear+1)%x->size;
        x->q[x->rear] = ele;
    }
    
}
void dequeue(struct queue* x)
{
    if(isEmpty(x)==1)
        printf("Queue is empty");
    else
    {
        x->front = (x->front+1)%x->size;
    }
    
}
int first(struct queue* x)
{
    if(isEmpty(x)==1)
        return -1;
    return x->q[(x->front+1)%x->size];
}
int last(struct queue* x)
{
    if(isEmpty(x)==1)
        return -1;
    return x->q[x->rear];
    
}
int main()
{

}



