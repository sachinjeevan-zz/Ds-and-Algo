#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int** mat = (int**)malloc(sizeof(int*)*M);
    int** dp = (int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*N);
        dp[i] = (int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&mat[i][j]);
            if(i==0 && j==0)
            {
                dp[0][0] = mat[0][0];
            }
            else if(i==0)
            {
                dp[0][j] = dp[0][j-1] + mat[0][j];
            }
            else if(j==0)
            {
                dp[i][0] = dp[i-1][0] + mat[i][0];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + mat[i][j];
            }
            
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
}