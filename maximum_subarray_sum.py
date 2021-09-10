n = int(input())
nums = list(map(int,input().split()))
msf,meh=float('-inf'),float('-inf')

for n in nums:
    meh+=n
    if meh<n:
        meh = n
    msf = max(msf,meh)

print(msf)