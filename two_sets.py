N = int(input())
if N*(N+1)/2 %2:
    print("NO")
else:
    v1 = list()
    v2 = list()

    if N%4 == 0:
        for i in range(0,(N-1)//2,2):
            v1.extend([i+1 , N-i])
            v2.extend([i+2,N-i-1])
    else:
        for i in range(0,(N-1)//2,2):
            v1.extend([i , N-i])
            v2.extend([i+1,N-i-1])
        v1.remove(0)
        

    print("YES",len(v1)," ".join([str(_) for _ in v1]),len(v2)," ".join([str(_) for _ in v2]),sep='\n')

