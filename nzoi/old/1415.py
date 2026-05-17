import math
from collections import defaultdict
N, M = map(int, input().split())
cities = []
res_list = []
for i in range(N):
    r, c = map(int, input().split())
    cities.append((r, c))

c2c = defaultdict(int)

for i in range(len(cities)):
    for j in range(i+1, len(cities)):
        ir, ic = cities[i][0], cities[i][1]
        jr, jc = cities[j][0], cities[j][1]

        dist = math.ceil(math.sqrt((jr-ir)**2 + (jc-ic)**2))
        c2c[(i, j)] = dist
        c2c[(j, i)] = dist

log = list(map(int, input().split()))
money = [0] * M
for i in range(len(log)-2, -1, -1):
    money[i] = money[i+1] + c2c[(log[i], log[i+1])]

for i in range(M):
    res = 0
    for f in range(N):
        cand = (i, f)
        if c2c[cand] and c2c[cand] <= money[i]:
            res += 1
    res_list.append(res)

print(" ".join(map(str, res_list)))
