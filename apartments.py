n,m,k = input().split(" ")
n = int(n)
m = int(m)
k = int(k)
desired = sorted(list(map(int,input().split(" "))))
apartment_size = sorted(list(map(int,input().split(" "))))
ans=0
j=0
for i in range(n):
    while j<m and (apartment_size[j] < (desired[i]-k )):
        j+=1
    if j<m and apartment_size[j] <= desired[i]+k:
        ans+=1
        j+=1

print(ans)

