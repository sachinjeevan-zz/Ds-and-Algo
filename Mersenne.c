#include<stdio.h>
int isPowerof2(int num)
{
    if(num>0 && ((num & (num-1)) ==0))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d",&N);
    int x,sum=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        if(x>0 && isPowerof2(x+1)==1)
            sum = sum + x;
    }
    printf("%d",sum);
}