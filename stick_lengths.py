n = int(input())
sticks = list(map(int,input().split()))
sticks = sorted(sticks)
p = sticks[n//2]
ans=0
for s in sticks:
    ans+=abs(s-p)

print(ans)

