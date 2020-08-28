#include<stdio.h>
#include<limits.h>
// N = 5 0 1 2 3 4 5 N+1
int max(int arr[],int N) // T(n) = 5n + 5   => O ( n )
{
    int maxElement= INT_MIN, maxIndex;// 2 unit
    for(int i=0;i<N;i++) // 1 unit // N+1 unit // N unit
    {
        if(arr[i]>maxElement) // N unit
        {
            maxElement=arr[i]; // N unit
            maxIndex = i; // N unit
        }
    }
    return maxIndex; // 1 unit
}
int main()
{ // T(n) = 4N^2 + 4N + 2  = > O(N^2)
    int N,K,index,sum=0;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&K);
    for(int j=0;j<K;j++) // 1 unit  // N+1 unit // N unit 
    {
        index = max(arr,N); // N^2 unit
        for(int i=index;i<N-1;i++) // N unit // N^2 unit // N^2 unit
        {
            arr[i] = arr[i+1]; // N^2 unit
        }
        N--; // N unit
    }
    for(int i=0;i<N;i++)
    {
        sum = sum + arr[i];
    }

    printf("%d",sum);
}