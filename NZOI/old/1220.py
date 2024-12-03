# Naive
from collections import defaultdict

_ = input()
N = int(input())

rows = defaultdict(list)  #row: col
cols = defaultdict(list)  #col: row

def swim():
    cr, cc = 0, 0
    X = list(map(int, input().split(" ")))
    inst_qty = X[0]
    down = X[1::2]
    right = X[2::2]
    output = "smooth swimming"

    for i in range(inst_qty):
        pr, pc = cr, cc
        cr, cc = cr + down[i], cc
        for r in cols[pc]:
            if pr <= r <= cr:
                output = "OUCH"
        cr, cc = cr, cc + right[i]
        for c in rows[cr]:
            if pc <= c <= cc:
                output = "OUCH"
            
    rows[cr].append(cc)
    cols[cc].append(cr)
    return output    

for i in range(N):
    print(swim())

# Binary Search
from collections import defaultdict
import bisect

_ = input()
N = int(input())

rows = defaultdict(list)  #row: col
cols = defaultdict(list)  #col: row

def swim():
    cr, cc = 0, 0
    X = list(map(int, input().split(" ")))
    inst_qty = X[0]
    down = X[1::2]
    right = X[2::2]
    output = "smooth swimming"

    for i in range(inst_qty):
        pr, pc = cr, cc
        cr = cr + down[i]
        if output == "smooth swimming":
            p = bisect.bisect_left(cols[cc], pr)
            if p != len(cols[cc]):
                if pr <= cols[cc][p] <= cr:
                    output = "OUCH"
        cc = cc + right[i]
        if output == "smooth swimming":
            p = bisect.bisect_left(rows[cr], pc)
            if p != len(rows[cr]):
                if pc <= rows[cr][p] <= cc:
                    output = "OUCH"
            
    bisect.insort(rows[cr], cc)
    bisect.insort(cols[cc], cr)
    return output    

for i in range(N):
    print(swim())
