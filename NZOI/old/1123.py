from collections import defaultdict
L = int(input())
inventory = defaultdict(int)
R, P, D, G = map(int, input().split())
inventory["R"], inventory["P"], inventory["D"], inventory["G"] = R, P, D, G
wanted = input()

output = False
ac = 0
initial = rtotal = R + P + D + G
ducktotal = R + P + D

for i in range(L):
    typee = wanted[i]
    if not ducktotal:
        output = True
        print(initial - rtotal + ac)
        print(rtotal - ac)
        break
    elif typee == ".":
        ac += 1
        ducktotal -= 1
    elif not inventory[typee]:
        output = True
        print(initial - rtotal + ac)
        print(rtotal - ac)
        break
    else:
        inventory[typee] -= 1
        rtotal -= 1
        if typee != "G":
            ducktotal -= 1

if not output:
    print(L)
    print(initial - L)
