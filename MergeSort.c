#include<stdio.h> 
void merge(int arr[],int start,int mid, int end)
{
    int N = mid - start+ 1,M = end-mid;
    int L[N],R[M],k=0;
    for(int i=start;i<=mid;i++)
    {
        L[k] = arr[i];
        k++;
    }
    k=0;
     for(int i=mid+1;i<=end;i++)
    {
        R[k] = arr[i];
        k++;
    }

    int i=0,j=0;
    while(i<N && j<M)
    {
        if(L[i]<R[j])
        {
            arr[start]= L[i];
            start++;
            i++;
        }
        else
        {
            arr[start] = R[j];
            start++;
            j++;
        }
        
    }
    if(i<N)
    {
        while(i<N)
        {
            arr[start]=L[i];
            start++;
            i++;
        }
    }
    if(j<M)
    {
        while(j<M)
        {
            arr[start]=R[j];
            start++;
            j++;
        }
    }
}
void mergeSort(int arr[],int start,int end)
{
    int mid = (start+end)/2;
    if(start<end)
    {
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int N,K,sum=0;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&K);
    mergeSort(arr,0,N-1);
    N=N-K;
    for(int i=0;i<N;i++)
    {
        sum = sum + arr[i];
    }
    printf("%d",sum);


}