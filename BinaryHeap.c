#include<stdio.h>
int main()
{
    int n,x,child,parent;
    scanf("%d",&n);
    int heap[n],i=0,temp;
    for(int j=0;j<n;j++)
    {
        scanf("%d",&x);
        heap[j] = x;
        child = j;
        while(child>0)
        {
            parent = ( child - 1)/2;
            if(heap[child]>heap[parent])
            {
                temp = heap[child];
                heap[child] = heap[parent];
                heap[parent] = temp;
                child = parent;
            }
            else
            {
                break;
            }
            
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",heap[i]);


}