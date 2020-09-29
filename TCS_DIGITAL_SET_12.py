'''
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
For example, consider the below binary matrix.
'''
m,n = map(int,input().split(" "))
mat,dp=[],[]
for i in range(m):
    x = list(map(int,input().split(" ")))
    mat.append(x)
    dp.append(x[::])
for i in range(1,m):
    for j in range(1,n):
        if(mat[i][j]==0):
            dp[i][j]=0
        else:
            dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1
x = list(map(max,dp))
print(max(x))