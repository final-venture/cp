d2q = {"S": 0, "M": 0, "L": 0}
d2q["S"], d2q["M"], d2q["L"] = int(input()), int(input()), int(input())

maxn = max(d2q.values())
xdd = sorted(d2q.items())

for s, x in xdd:
    n = (maxn - x) // 2
    ur = "_" * n
    if (maxn - x) % 2:
        ul = ur + "_"
    else:
        ul = ur
    
    print(f"{ur}{s*x}{ul}")
