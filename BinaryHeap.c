#include<stdio.h>
#include<stdlib.h>
struct BHeap
{
    int *heap;
    int size;
    int length;
};
struct BHeap* BinaryHeap(int n)
{
    struct BHeap* x = (struct BHeap*)malloc(sizeof(struct BHeap));
    x ->size = n;
    x->heap=  (int*)malloc(sizeof(int)*x->size);
    x->length = 0;
    return x;
}
int isEmpty(struct BHeap* x)
{
    if(x->length==0)
        return 1;
    return 0;
}
void insert(struct BHeap* x, int y)
{
    int i = x->length,temp;
    x->heap[i] = y;
    x->length++;
    while(i!=0)
    {
        int k = (i-1)/2;
        if(x->heap[i] > x->heap[k])
        {
            temp = x->heap[i];
            x->heap[i] = x->heap[k];
            x->heap[k] = temp;
            i=k;
        }
        else
        {
            break;
        }
    }
    
}
int findMax(struct BHeap* x)
{
    if(isEmpty(x)==1)
        return -1;
    return x->heap[0];
}
int extractMax(struct BHeap* x)
{
    if(isEmpty(x)==1)
        return -1;
    int temp = x->heap[0],z;
    x->heap[0] = x->heap[x->length-1];
    x->length--;
    int i=0;
    while(2*i+1<x->length)
    {
        if(2*i+1<x->length && 2*i+2<x->length)
        {
            int k = x->heap[2*i+1]>x->heap[2*i+2]?2*i+1:2*i+2;
            if(x->heap[i]<x->heap[k])
            {
                z = x->heap[i];
                x->heap[i] = x->heap[k];
                x->heap[k] = z;
                i=k;
            }
            else
            {
                break;
            }
            
        }
        else if( 2*i+1<x->length)
        {
            int k = 2*i+1;
            if(x->heap[i]<x->heap[k])
            {
                z = x->heap[i];
                x->heap[i] = x->heap[k];
                x->heap[k] = z;
                i=k;
            }
            else
            {
                break;
            }
        }
    }
    return temp;
}
int size(struct BHeap* x)
{
    return x->length;
}
int main()
{
    struct BHeap* x = BinaryHeap(7);
    insert(x,23);
    insert(x,12);
    insert(x,19);
    insert(x,35);
    insert(x,33);
    insert(x,42);
    insert(x,25);
    printf("%d\n",extractMax(x));
    for(int i=0;i<x->length;i++)
    {
        printf("%d ",x->heap[i]);
    }


}