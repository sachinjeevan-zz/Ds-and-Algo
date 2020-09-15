#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int fib(int n)
{
    return ceil((pow(((1.0 + sqrt(5))/2.0),n)  -  pow(((1.0 - sqrt(5))/2.0),n))/sqrt(5));
}
int* sieveOfEratosthene(int m)
{
    int* arr = (int*)malloc(sizeof(int)*(m-1));
    for(int i=0;i<m-1;i++)
    {
        arr[i] = i+2;
    }
    for(int i=0;arr[i]*arr[i]<=m;i++)
    {
        if(arr[i]!=0)
        {
            for(int j=arr[i]*arr[i]-2;j<m-1;j+=arr[i])
            {
                arr[j] = 0;
            }
        }
    }
    int* primes = (int*)malloc(sizeof(int)*(m-1));
    for(int i=0,k=0;i<m-1;i++)
    {
        if(arr[i]!=0)
        {
            primes[k++] = arr[i];
        }
    }
    return primes;
}
int main()
{
    int* primes = sieveOfEratosthene(100000);
    int n;
    scanf("%d",&n);
    if(n%2!=0)
    {
        printf("%d",fib((n+1)/2));
    }
    else
    {
        printf("%d",primes[n/2-1]);
    }
}

// 1 2 1 3 2 5 3 7 5 11 8 13 13 17