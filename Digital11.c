#include<stdio.h>
int arithmeticProgression(int a1,int n,int d)
{
    return a1+(n-1)*d;
}
int main()
{
    int num;
    scanf("%d",&num);
    if(num%2==0)
        printf("%d",arithmeticProgression(0,num/2,1));
    else
        printf("%d",arithmeticProgression(0,(num+1)/2,2));
}