from collections import defaultdict

N, A = map(int, input().split())
area = defaultdict(list)
for _ in range(N):
    for r, c in [list(map(int, input().split()))]:
        top, bottom, left, right = max(r - A, 0), r + A, max(c - A, 0), c + A
        for row in range(top, bottom + 1):
            area[row].append((left, right))

uc = 0
for row in area:
    tgt = []
    for start, end in sorted(area[row]):
        if tgt and tgt[-1][1] >= start:
            tgt[-1] = (tgt[-1][0], max(tgt[-1][1], end))
        else:
            tgt.append((start, end))
    uc += sum(end - start + 1 for start, end in tgt)

print(uc)
