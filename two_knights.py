"""
Really, a great explanation : https://youtu.be/12Y8OrlRS3U
"""
N = int(input())
for k in range(1,N+1):
    print(pow(k,2)*(pow(k,2)-1)//2 - 4*(k-1)*(k-2))
 