#include<stdio.h>
#include<stdlib.h>
int minWeight(int **mat,int m, int n)
{
    int minWeight = mat[0][0];
    int i=0,j=0;
    while(i!=m-1 ||  j!=n-1)
    {
        if(i!=m-1 && j!=n-1)
        {
            if(mat[i][j+1] < mat[i+1][j])
            {
                if(mat[i][j+1]>minWeight)
                {
                    minWeight = mat[i][j+1];
                    
                }
                j++;
            }
            else
            {
                if(mat[i+1][j]>minWeight)
                {
                    minWeight = mat[i+1][j];
                  
                }
                  i++;
            }
        }
        else if( i==m-1)
        {
            if(mat[i][j+1]>minWeight)
            {
                minWeight = mat[i][j+1];
            }
            j++;
        }
        else if( j==m-1 )
        {
            if(mat[i+1][j]>minWeight)
            {
                minWeight = mat[i+1][j];
            }
            i++;
        }
    }
    return minWeight;
    
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int **mat = (int**)malloc(sizeof(int*) * m);
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
    int min = minWeight(mat,m,n);
    printf("%d",min);

}