#include<stdio.h>
#include<stdlib.h>
int uniqueDigits(int num)
{
    int *hash = (int*)calloc(10,sizeof(int));
    while(num)
    {
        if(hash[num%10]!=0)
            return 0;
        hash[num%10]++;
        num/=10;
    }
    return 1;
}
int uniqueDigitsBIT(int num)
{
    short int x=0,y;

    while(num)
    {
        y = 1 << num%10;
        if((x&y)==0)
            x = x | y;
        else
            return 0;
        num/=10;
    }
    return 1;

}
int main()
{
    int t;
    scanf("%d",&t);
    int n = 100000;
    int arr[100001];
    arr[0] = 1;
    for(int i=1;i<=100000;i++)
    {
        arr[i] = arr[i-1] + uniqueDigitsBIT(i);
    }
    int start,end,count=0;
    while(t--)
    {     
        scanf("%d %d",&start,&end);
        printf("%d\n",arr[end]-arr[start-1]);
    }


}