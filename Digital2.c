#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* sieveEratosthene(int n)
{
    int *prime = (int*)malloc(sizeof(int)*(n-1));
    for(int i=0;i<n-1;i++)
    {
        prime[i] = i+2;
    }
    for(int i=0;prime[i]<=sqrt(n);i++)
    {
        if(prime[i]!=0)
        {
            for(int j=(prime[i]*prime[i])-2;j<n-1;j+=prime[i])
            {
                prime[j] = 0;
            }
        }
    }
    return prime;
}
int* sieveSundaram(int n)
{
    int k = ((n-1)/2);
    int *arr = (int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++)
    {
        arr[i] = i+1;
    }
    int i=1,j=1,z;
    while((i + j + 2*i*j)<=k)
    {
        z = (i + j + 2*i*j);
        while(z<=k)
        {
            arr[z-1]=0;
            j++;
            z = (i + j + 2*i*j);
        }
        i++;
        j=i;
    }
    return arr;
}
// 0 1 2 3
// 2 3 4 5
int main()
{
    int t,start,end;
    scanf("%d",&t);
    int* arr = sieveEratosthene(2000);
    while(t--)
    {
        scanf("%d %d",&start,&end);
        for(int i=start-2;i<=end-8;i++)
        {
            if(arr[i]!=0 && arr[i+6]!=0)
            {
                printf("(%d,%d) ",arr[i],arr[i+6]);
            }
        }
        printf("\n");
    }
    
}

// 5 6 7 8 9 10 11 12 13 14 15 16