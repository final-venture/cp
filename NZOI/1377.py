from collections import defaultdict
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sync = defaultdict(int)

for x in b:
    for y in a:
        sync[x-y] += 1

print(2*n - max(sync.values()))
