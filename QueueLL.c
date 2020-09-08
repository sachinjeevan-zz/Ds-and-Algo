#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct queue
{
    struct Node* front;
    struct Node* rear;
};
struct queue* QueueLLInit()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(struct queue* q)
{
    if(q->front==NULL)
        return 1;
    return 0;
}
void enqueue(struct queue* q, int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
        printf("Queue is Full");
    else
    {
        newNode->data = x;
        newNode->next = NULL;
        if(isEmpty(q)==1)
            q->front = q->rear = newNode;
        else
        {
            q->rear->next = newNode;
            q->rear = newNode;
        }
        
    }
    
}
void dequeue(struct queue* q)
{
    if(isEmpty(q)==1)
        printf("Queue is Empty");
    else
    {
        struct Node* d = q->front;
        q->front = q->front->next;
        free(d);
    }
    
}
int first(struct queue* q)
{
    if(isEmpty(q)==1)
        return -1;
    return q->front->data;
}
int last(struct queue* q)
{
    if(isEmpty(q)==1)
        return -1;
    return q->rear->data;
}
int main()
{
    struct queue* q = QueueLLInit();
    enqueue(q,12);
    enqueue(q,23);
    enqueue(q,34);
    enqueue(q,45);
    enqueue(q,54);
    enqueue(q,63);
    dequeue(q);
    dequeue(q);
    printf("%d %d",first(q),last(q));
}