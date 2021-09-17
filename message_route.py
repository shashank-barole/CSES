from collections import deque,defaultdict
import collections
n,m = input().split()
n = int(n)
m = int(m)
adj = defaultdict(list)
def bfs(v):
    p = [0]*(n+1)
    p[v]=-1
    q = deque()
    q.append(v)
    used=[0]*(n+1)
    used[v]=1
    while q:
        u = q.popleft()
        for v1 in adj[u]:
            if used[v1]==0:
                used[v1]=1
                q.append(v1)
                p[v1]=u

    return p,used
for i in range(m):
    u,v = input().split()
    u = int(u)
    v = int(v)
    adj[u].append(v)
    adj[v].append(u)

p1,u = bfs(1)
if u[n]==0:
    print("IMPOSSIBLE")
else:
    path = []
    u = n
    while p1[u]!=-1:
        path.append(str(u))
        u = p1[u]
    path.append(str(u))
    print(len(path))
    print(" ".join(reversed(path)))




