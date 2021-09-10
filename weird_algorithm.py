n=int(input())
print(n,end=" ")
while n!=1:
    if n&1:
        n*=3
        n+=1
    else:
        n//=2
    print(n,end=" ")