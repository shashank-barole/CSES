from collections import defaultdict
n = int(input())
bosses = list(map(int,input().split()))
adj = defaultdict(list)
for i in range(len(bosses)):
    adj[bosses[i]].append(i+2)
subords =  defaultdict(int)
def dfs(v):
    if not adj[v]:
        return 0
    if v in subords:
        return subords[v]

    subords[v]=0
    for conn in adj[v]:
        subords[v]+= 1 + dfs(conn)
    return subords[v]

for i in range(n,0,-1):
    subords[i]=dfs(i)

for i in range(1,n+1):
    print(subords[i],end=" ")