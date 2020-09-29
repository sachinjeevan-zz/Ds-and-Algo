/*
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
For example, consider the below binary matrix.
*/
#include<stdio.h>
int min(int a,int b,int c)
{
    return (a<b && a<c) ? a: b<c?b:c;
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int mat[m][n],dp[m][n],max = 0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
            if(i==0 || j==0)
            {
                dp[i][j] = mat[i][j];
            }
            else
            {
                if(mat[i][j]==1)
                {
                   dp[i][j] =  min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
                   if(dp[i][j]>max)
                        max = dp[i][j];
                }
                else
                {
                    dp[i][j]=0;
                }
                
            }
            
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
}