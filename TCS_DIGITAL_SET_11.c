/*
In the amusement park at Looney‟s amusement, there is a “Weighted Maze”
challenge. This consists of a set of East West roads (referred to as left to right roads)
and North South roads (referred to as up down roads). Each intersection has a block
of iron bar, the weight of which is given. You enter the maze at the top left corner with
1 kg in a cart. The exit from the maze is at the bottom right corner. Movement at any
intersection is to the right or down provided a road exists in that direction.
At each intersection you pass through, you must exchange the weight in your cart with
the weight of the bar at the intersection if it is heavier than the weight you have in the
cart.
The objective is to determine a path through the maze along the roads so that one can
exit the maze with the minimum weight in the cart.
For example, in the maze shown, the least weight one can exit the maze is 22 kg.
-> 1 8 21 7
19 17 10 20
2 18 23 22
14 25 4 13 ->
Input:
The first line consists of a positive integer n, which is the number of intersection in any
up-down or left-right road.
The next n lines each consist of n positive integers representing the weights at the
intersections in the corresponding left-right road
Output:
A positive integer that represents the minimum weight possible in the cart when exiting
the maze.
Example
Input
4
1,8,21,7
19,17,10,20
2,18,23,22
14,25,4,13
Output
22
*/
#include<stdio.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int mat[m][n],dp[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    dp[0][0] = mat[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i] =max(dp[0][i-1],mat[0][i]);
    }
    for(int i=1;i<m;i++)
    {
        dp[i][0] = max(dp[i-1][0],mat[i][0]);
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = max(min(dp[i][j-1],dp[i-1][j]),mat[i][j]);
        }
    }
    printf("%d",dp[m-1][n-1]);
}