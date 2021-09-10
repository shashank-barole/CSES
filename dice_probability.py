n,a,b = input().split()
n = int(n)
a = int(a)
b = int(b)
dp = [[0 for j in range(601)] for i in range(101)]
ans=0
dp[0][0]=1
for i in range(n):
    for j in range(i,6*i+1):
        for k in range(1,7):
            dp[i+1][j+k]+= dp[i][j]/6

for i in range(a,b+1):
    ans+=dp[n][i]

print(f"{ans:.6f}")