n = int(input())
arr = list(map(int,input().split(" ")))
LIS = [1]*n
i,j=0,1
max,ind=1,0
while(j<n):
    i=0
    while(i<j):
        if(arr[j]>=arr[i]):
            if(LIS[i]+1>LIS[j]):
                LIS[j] = LIS[i]+1
                if(LIS[j]>max):
                    max = LIS[j]
                    ind = j
        i+=1
    j+=1
ans =[]
while(max>0):
    if(LIS[ind]==max):
        ans.append(arr[ind])
        max-=1
        ind-=1
    else:
        ind-=1
ans.reverse()
print(*ans)
