"""
Got TLE
"""

from bisect import bisect_left
n,m = input().split(" ")
n = int(n)
m = int(m)
ticket_price = sorted(list(map(int,input().split())))
max_price = list(map(int,input().split()))
ticket_price.sort()
for p in max_price:
    idx = bisect_left(ticket_price,p)
    if idx < len(ticket_price) and ticket_price[idx] == p:
        print(ticket_price[idx])
        ticket_price.pop(idx)
    
    elif idx>0:
        print(ticket_price[idx-1])
        ticket_price.pop(idx-1)
    
    else:
        print(-1)




