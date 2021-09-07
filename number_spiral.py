t=int(input())
while t:
    x,y = input().split(" ")
    y = int(y)
    x = int(x)
    if x==y==0:
        print(1)
    elif x==y:
        print((pow(x,2) - x+1))
    else:
        if x>y:
            if x%2:
                max_v = (pow(x,2) - x+1)
                print(max_v - (x - y))
            else:
                max_v = (pow(x,2) - x+1)
                print(max_v + (x - y))

        else:
            if y%2:
                max_v = (pow(y,2) - y+1)
                print(max_v + (y -x))
            else:
                max_v = (pow(y,2) - y+1)
                print(max_v - (y-x))
    t-=1


