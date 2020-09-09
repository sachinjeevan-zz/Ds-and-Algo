#include<stdio.h>
#include<stdlib.h>
int maxMatrixSum(int** mat, int m, int n,int k)
{
    int **dp = (int**)malloc(sizeof(int*)*m); 
    for(int i=0;i<m;i++)
    {
        dp[i] = (int*)malloc(sizeof(int)*n);
    }
    dp[0][0] = mat[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i] = dp[0][i-1] + mat[0][i];
    }
    for(int i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] + mat[i][j] - dp[i-1][j-1];
        }
    }
    int max = INT_MIN,ans,row,col;
    for(int i=k-1;i<m;i++)
    {
        for(int j=k-1;j<n;j++)
        {
            if((i-k)>=0 && (j-k)>=0)
            {
                ans = dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k];
            }
            else if(j-k>=0)
            {
                ans = dp[i][j] - dp[i][j-k];
            }
            else if(i-k>=0)
            {
                ans = dp[i][j] - dp[i-k][j];
            }
            else
            {
                ans = dp[i][j];
            }
            if(ans>max)
                {
                    max = ans;
                    row = i-k+1;
                    col = j-k+1;
                }
            
        }
    }
    for(int i=row;i<row+k;i++)
    {
        for(int j=col;j<col+k;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return max;

    
}
int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
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
    printf("%d",maxMatrixSum(mat,m,n,k));
}