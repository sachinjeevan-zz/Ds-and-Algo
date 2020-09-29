#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int W[N],P[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&W[i]);
    }
    for(int i=0;i<N;i++)
    {
        scanf("%d",&P[i]);
    }
    int dp[N+1][K+1];
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<K+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
            {
                if(W[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = max(dp[i-1][j-W[i-1]]+P[i-1],dp[i-1][j]);
                }
                
            }
            
        }
    }
     for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<K+1;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    int i=N,j=K;
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else
        {
            printf("(%d,%d) ",W[i-1],P[i-1]);
            j = j-W[i-1];
            i--;
        }
    }
    
}