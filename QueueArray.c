#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int* q;
    int size;
    int rear,front;
};
struct queue* queueInit(int n)
{
    struct queue* x = (struct queue*)malloc(sizeof(struct queue));
    x->size = n;
    x->q = (int*)malloc(sizeof(int)*x->size);
    x->front = x->rear = -1;
    return x;
}
int isFull(struct queue* x)
{
    if(x->rear == x->size-1)
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
        printf("Queue is Full");
    else
    {
        x->rear++;
        x->q[x->rear] = ele;
    }
    
}
void dequeue(struct queue* x)
{
    if(isEmpty(x)==1)
        printf("Queue is Empty");
    else
        x->front++;
}
int first(struct queue* x)
{
    if(isEmpty(x)==1)
        return -1;
    return x->q[x->front+1];
}
int last(struct queue* x)
{
    if(isEmpty(x)==1)
        return -1;
    return x->q[x->rear];
}
int main()
{
   struct queue* x = queueInit(5);
   enqueue(x,10);
   enqueue(x,43);
   enqueue(x,56);
   enqueue(x,63);
   dequeue(x);
   dequeue(x);
   printf("%d %d",first(x),last(x));
}