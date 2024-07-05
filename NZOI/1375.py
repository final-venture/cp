from collections import defaultdict
import bisect

def sum_series(f, n):
    i = f - n + 1
    return (n * (i + f)) // 2

N, Q = map(int, input().split())
pinecones = list(map(int, input().split()))
pinecones.sort()
inorder = []
dp = defaultdict(int)

for i in range(Q):
    dp.append(int(input()))
dp.sort()

for i in range(Q):
    req = int(input())
    res = 0
    while req:
        max1 = pinecones.pop()
        if max1 <= 0:
            break
        max2 = pinecones[-1]
        diff = max1 - max2
        throws = min(diff + 1, req)
        total_height_gain = sum_series(max1, throws)
        res += total_height_gain
        req -= throws
        bisect.insort(pinecones, max1 - throws)
    print(res % 1000000007)
