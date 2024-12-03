from collections import defaultdict
N = int(input())
towers = list(map(int, input().split()))

last = 0
visible = defaultdict(int)
visible_l = []
safe = [0] * len(towers)
consec = defaultdict(int)

visible[towers[0]] += 1
visible_l.append(towers[0])

for i in range(1, len(towers)):
    q = 1 if consec[towers[i]] else 2
    if visible[towers[i]] != 0:
        safe[i] = safe[i-1] + q
        consec[towers[i]] = True
    else:
        safe[i] = safe[i-1]
        consec[towers[i]] = False
    if towers[i] >= towers[i-1]:
        while visible_l and visible_l[-1] <= towers[i]:
            visible[visible_l.pop()] -= 1
    visible[towers[i]] += 1
    visible_l.append(towers[i])

for i, v in enumerate(safe):
    print(i + 1 - v)
