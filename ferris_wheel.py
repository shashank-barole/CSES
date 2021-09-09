n,x = input().split()
n = int(n)
x = int(x)
weights = list(map(int,input().split()))
ans=0
weights.sort()
i,j = 0,n-1
while i<=j:
    while i<=j and (weights[i]+weights[j]) > x:
        ans+=1
        j-=1
    if i<=j and (weights[i]+weights[j]) <=x:
        ans+=1
        i+=1
        j-=1

print(ans)
        
    
