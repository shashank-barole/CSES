conf = list()
for i in range(8):
    conf.append(list(input()))
neg = set()
pos = set()
cols = set()
ans=0
def dfs(r):
    global ans
    if r==8:
        ans+=1
        return
    
    for c in range(8):
        if (r-c) in neg or (r+c) in pos or conf[r][c]=="*" or c in cols:
            continue

        cols.add(c)
        pos.add(r+c)
        neg.add(r-c)
        conf[r][c]='Q'
        dfs(r+1)
        cols.remove(c)
        pos.remove(r+c)
        neg.remove(r-c)
        conf[r][c]='.'

dfs(0)
print(ans)
    

