import bisect
N, Q = map(int, input().split())
H = list(map(int, input().split()))

cones = [0] * 100001

for cone in H:
    cones[cone] += 1 

A = [0] * 100002
B = [0] * 100002

num = 0
for i in range(100000, -1, -1):
    num += cones[i]
    A[i] = A[i+1] + num
    B[i] = B[i+1] + num * i

for i in range(Q):
    req = int(input())
    nearest_idx = bisect.bisect_right(B, req)
    print(nearest_idx)
    if nearest_idx == 0:
        res = B[0]
    else:
        res = B[nearest_idx] + (req - A[nearest_idx]) * (nearest_idx - 1)
    print(res % 1000000007)
