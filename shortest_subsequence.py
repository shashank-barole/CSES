import sys
sys.setrecursionlimit(10000000)
sequence = input()
DNA_seq = "ATGC"
found=False
l = len(sequence)
result = ""
def solve(i):
    global result,found
    if (l-i) < 4:
        have = sequence[i:]
        for ch in ['A','T','G','C']:
            if ch not in have:
                result+=ch
                break
        found=True
        return

    if i >= l:
        found=True
        result+= 'A'
        return

    check = dict.fromkeys(DNA_seq,False)
    for j in range(i,l):
        check[sequence[j]] = True

        if all(check.values()):
            result+=sequence[j]
            solve(j+1)
            if found:
                return
    if not all(check.values()):
        have = sequence[i:]
        for ch in ['A','T','G','C']:
            if ch not in have:
                result+=ch
                break
        found=True
        return

solve(0)
print(result)


