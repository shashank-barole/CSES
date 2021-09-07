N = int(input())
result = list()

if N==1:
    print(1)
elif N==2 or N==3:
    print("NO SOLUTION")
else:
    if N%2==0:
        for i in range(2,N+1,2):
            result.append(i)
        for i in range(1,N,2):
            result.append(i)
    else:
        for i in range(2,N,2):
            result.append(i)
        for i in range(1,N+1,2):
            result.append(i)
    print(" ".join([str(i) for i in result]))
