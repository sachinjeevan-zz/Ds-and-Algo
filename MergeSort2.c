#include<stdio.h>
void merge(int arr[],int start,int mid, int end) // O(n) 
{
    //start = 0    end = 3               mid - start + 1     end - mid
    // Finding the size of Left array and right array
    //   mid+1  end     end - (mid+1) + 1 = end - mid 
    int N = mid - start + 1,M = end - mid; // 3 unit
    // Taken two array ( Left , Right)
    int L[N],R[M],k=0; // 3 unit
    // Copying left part elements to L array
    for(int i=start;i<=mid;i++) // 1 unit // n/2 + 1 unit // n/2 unit
    {
        L[k] = arr[i]; // n/2 unit
        k++; // n/2 unit
    }
    k=0; // 1 unit
    // Copying right part elements to R array
    for(int i=mid+1;i<=end;i++)// 1 unit // n/2 + 1 unit // n/2 unit
    {
        R[k] = arr[i]; // n/2 unit
        k++; // n/2 unit
    }
    int i=0,j=0;
    // Merging   n unit
    while(i<N && j<M)
    {
        if(L[i] < R[j])
        {
            arr[start] = L[i];
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
    // copying left out elements
    while(i<N)
    {
        arr[start] = L[i];
        start++;
        i++;
    }
    while(j<M)
    {
        arr[start] = R[j];
        start++;
        j++;
    }
    
}
void mergeSort(int arr[], int start, int end) // T(n) = 2*T(n/2) + n + 1   T(1) = 1
{
    int mid = (start+end)/2; // 2 unit
    if(start<end) // 1 unit
    {
        mergeSort(arr,start,mid); // T(n/2)
        mergeSort(arr,mid+1,end); // T(n/2)
        merge(arr,start,mid,end); // n unit
    }
}
int main()
{
    int N,K;
    scanf("%d",&N);
    int arr[N],sum=0;
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