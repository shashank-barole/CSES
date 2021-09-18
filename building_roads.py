import sys
sys.setrecursionlimit(1000000)
from collections import defaultdict
cities,roads = input().split()
cities = int(cities)
roads = int(roads)
result=list()
adj = defaultdict(list)
visit = [False]*(cities+1)
def dfs(v):
    global visit
    visit[v]=True
    for u in adj[v]:
        if not visit[u]:
            dfs(u)
for i in range(roads):
    a,b = input().split()
    a = int(a)
    b = int(b)
    adj[a].append(b)
    adj[b].append(a)


for i in range(1,cities+1):
    if not visit[i]:
        dfs(i)
        result.append(i)

print(len(result)-1)
for i in range(1,len(result)):
    print(result[i-1],result[i])