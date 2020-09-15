#include<stdio.h>
#include<math.h>
int geometricProgression(int a,int n,int r)
{
    return a*pow(r,n-1);
}
int main()
{
    int num;
    scanf("%d",&num);
    if(num%2==0)
        printf("%d",geometricProgression(1,num/2,3));
    else
        printf("%d",geometricProgression(1,(num+1)/2,2));
}