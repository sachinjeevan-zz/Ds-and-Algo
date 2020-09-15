#include<stdio.h>
#include<stdlib.h>
int min(int a,int b,int c)
{
    return a<b && a<c ? a : b<c ? b: c;
}
int squareSubMatrix(int** mat,int m,int n)
{
    int maxK=0;
    int **dp = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++)
    {
        dp[i] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = mat[i][j];
                if(dp[i][j]>maxK)
                    maxK = dp[i][j];
            }
            else
            {
                if(mat[i][j]==1)
                {
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1;
                    if(dp[i][j]>maxK)
                        maxK = dp[i][j];
                }
                else
                    dp[i][j] = mat[i][j];
            }
            
        }
    }
    return maxK;
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int **mat = (int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d",squareSubMatrix(mat,m,n));

}