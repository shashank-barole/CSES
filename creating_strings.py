from itertools import permutations
string = input()
string = sorted(string)
perms = set(permutations(string))
perms = sorted(list(perms))
print(len(perms))
for perm in perms:
    print("".join(list(perm)))