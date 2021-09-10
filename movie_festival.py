n = int(input())
intervals = list()
for i in range(n):
    s,e = input().split()
    s = int(s)
    e = int(e)
    intervals.append([s,e])

intervals = sorted(intervals,key = lambda x:x[1])

ans=1
l = intervals[0][1]
for s,e in intervals[1:]:
    if s >= l:
        ans+=1
        l = e
    
print(ans)



