from collections import defaultdict
N, M = map(int, input().split())
apples = list(map(int, input().split()))
branches = defaultdict(list)

for i in range(N-1):
    a, b = map(int, input().split())
    branches[a].append(b)

best = float("inf")
def dfs(i, sum):
    global M, best
    if sum >= M:
        if sum - M < best - M:
            best = sum
        return
    for apple in branches[i]:
        dfs(apple, sum + apples[apple])

dfs(0, apples[0])
print(best)
