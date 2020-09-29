#include<stdio.h>
int kSegment(int arr[],int N,int x,int k)
{
    int i=0,flag;
    while(i<N)
    {
        flag=0;
        for(int j=i;j<N&&j<i+k;j++)
        {
            if(arr[j]==x)
                flag=1;
        }
        if(flag==0)
            return 0;
        i = i+k;
    }
    return 1;
}
int main()
{
    int N,x,k;
    scanf("%d %d %d",&N,&x,&k);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(kSegment(arr,N,x,k)==1)
        printf("YES");
    else
    {
        printf("NO");
    }
    

}