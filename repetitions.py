string = input()
cur = string[0]
ans=1
max_c=1
for c in string[1:]:
    if c==cur:
        ans+=1
        max_c = max(max_c,ans)
    else:
        cur = c
        ans=1

print(max_c)
