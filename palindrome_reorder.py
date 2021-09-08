from collections import Counter
string = input()
counts = Counter(string)
odd_ct=0
for v in counts.values():
    odd_ct+= v&1
if odd_ct>1:
    print("NO SOLUTION")
else:
    odd_c = None
    for k,v in counts.items():
        if v&1:
            odd_c = k
            break
    l = len(string)
    result = list(range(l))
    if odd_c:
        result[l//2]=odd_c
        counts[odd_c]-=1
    add=0
    for k,v in counts.items():
        for i in range(0,v,2):
            result[add] = k
            result[l-add-1] = k
            add+=1

    print("".join(result))




