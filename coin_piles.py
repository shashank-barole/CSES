"""
Video Explanation : https://youtu.be/7HBKYby6nPM
"""


t = int(input())
results=list()
while t:
    a,b = input().split(" ")
    a = int(a)
    b = int(b)
    d = abs(a-b)
    min_n = min(a,b) - d
    if min_n==0 or (min_n>0 and min_n%3==0):
        print("YES")
    else:
        print("NO")
    t-=1


