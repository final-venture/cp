AA, BB, K = map(int, input().split())
B = max(AA, BB)
A = min(AA, BB)

best_qty = float("inf")
best_rmn = float("inf")

for i in range(K):
    if A * i >= K:
        rmn = A * i - K
        if rmn < best_rmn or rmn == best_rmn and i < best_qty:
            best_rmn = rmn
            best_qty = i
    else:
        left = K - A * i
        b_low = left // B
        b_high = b_low + 1

        if left - b_low * B <= b_high * B - left:
            best_b = b_low
        else:
            best_b = b_high
        
        rmn = abs(left - best_b * B)
        if rmn < best_rmn or rmn == best_rmn and i + best_b < best_qty:
            best_rmn = rmn
            best_qty = i + best_b

print(best_rmn, best_qty)
