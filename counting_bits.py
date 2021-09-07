from math import log2,floor
N = int(input())

def solve(n):
    if n==0:
        return 0
    if n==1:
        return 1
    
    x = floor(log2(n))
    return (x* (1 << (x-1))) + (n - (1 << x) + 1) + solve(n - (1 << x))

print(solve(N))
    
