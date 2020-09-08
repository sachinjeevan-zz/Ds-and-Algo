#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int *s;
    int size;
    int top;
};
struct stack* stackInit(int n)
{
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->size = n;
    st->s = (int*)malloc(sizeof(int)*st->size);
    st->top = -1;
    return st;
}
int isFull(struct stack* st)
{
    return st->top == st->size - 1 ? 1 : 0;
}
int isEmpty(struct stack* st)
{
    return st->top==-1?1:0;
}
void push(struct stack* st,int x)
{
    if(isFull(st)==1)
        printf("Stack Overflow");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
    
}
void pop(struct stack* st)
{
    if(isEmpty(st)==1)
        printf("Stack Underflow");
    else
    {
        st->top--;
    }
    
}
int stackTop(struct stack* st)
{
    if(isEmpty(st)==1)
        return -1;
    return st->s[st->top];
}
int peek(struct stack* st, int pos)
{
    int ind = st->top - pos + 1;
    if(ind<0)
        return -1;
    return st->s[ind];
}
int main()
{
    struct stack* st = stackInit(5);
    push(st,12);
    push(st,23);
    push(st,34);
    push(st,45);
    push(st,56);
    push(st,100);
    printf("%d",peek(st,4));
}