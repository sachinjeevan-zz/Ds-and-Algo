#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
int isEmpty(struct Node* top)
{
    return top==NULL?1:0;
}
struct Node* push(struct Node* top, int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    return top;
}
struct Node* pop(struct Node* top)
{
    if(isEmpty(top)==1)
        return NULL;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}
int stackTop(struct Node* top)
{
    if(isEmpty(top)==1)
        return -1;
    return top->data;
}
int peek(struct Node* top,int pos)
{
    for(int i=0;top!=NULL && i<pos-1;i++)
    {
        top = top->next;
    }
    if(top==NULL)
        return -1;
    return top->data;
}
int main()
{
    struct Node* top = NULL;
    top = push(top,23);
    top = push(top,34);
    top = push(top,45);
    top = push(top,56);
    printf("%d",peek(top,2));

}