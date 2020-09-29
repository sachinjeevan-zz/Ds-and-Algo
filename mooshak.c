#include<stdio.h>
#include<stdlib.h>
int isPath(int **maze, int M, int N, int i,int j)
{
    if(maze[i][j]==9)
        return 1;
    else
    {
        maze[i][j] = -1;
        if(i-1>=0 && maze[i-1][j]>0)
        {
            return isPath(maze,M,N,i-1,j);
        }
        if(j-1>=0 && maze[i][j-1]>0)
        {
            return isPath(maze,M,N,i,j-1);
        }
        if(i+1<M && maze[i+1][j]>0)
        {
            return isPath(maze,M,N,i+1,j);
        }
        if(j+1<N && maze[i][j+1]>0)
        {
            return isPath(maze,M,N,i,j+1);
        }
        maze[i][j] = 1;
    }
    return 0;
    
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int **mat = (int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
   if(isPath(mat,M,N,0,0)==1)
   {
       printf("YES");
   }
   else
   {
       printf("NO");
   }
   
}
//

-1  1   1

1 0   1

1  1   0