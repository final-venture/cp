from collections import defaultdict
rows = defaultdict(int)
cols = defaultdict(int)
mvmtc = mvmtr = 0

N = int(input())
for i in range(N):
    col, row = map(int, input().split(" "))
    cols[col] += 1
    rows[row] += 1
    mvmtc += col
    mvmtr += row

mmvmtc, mmvmtr = mvmtc, mvmtr

last = 0
tb4 = 0
ta = sum(cols.values())
# print(mvmtc)

for c, q in sorted(cols.items()):
    # print(c, q)
    diff = c - last
    # print(diff, ta, tb4)
    mvmtc = mvmtc - diff * ta + diff * tb4
    mmvmtc = min(mvmtc, mmvmtc)
    tb4 += q
    ta -= q
    last = c
    # print(mvmtc)
    
last = 0
tb4 = 0
ta = sum(rows.values())
# print(mvmtr)

for r, q in sorted(rows.items()):
    diff = r - last
    mvmtr = mvmtr - diff * ta + diff * tb4
    mmvmtr = min(mvmtr, mmvmtr)
    tb4 += q
    ta -= q
    last = r
    # print(mvmtr)

print(min(mmvmtc, mmvmtr))
