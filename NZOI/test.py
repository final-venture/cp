A, B, K = map(int, input().split())
best_diff = K
best_boxes = 0

if K == 0:
    print(0, 0)

for i in range(K//A):
    if A * i >= K:
        diff = A * i - K
        if diff < best_diff or diff == best_diff and i < best_boxes:
            best_diff = diff
            best_boxes = i
    else:
        remaining = K - A * i
        b_low = remaining // B
        b_high = remaining // B + 1
        if remaining - b_low * B <= b_high * B - remaining:
            best_b = b_low
        else:
            best_b = b_high
        
        diff = abs(remaining - best_b * B)
        if diff < best_diff or diff == best_diff and i + best_b < best_boxes:
            best_diff = diff
            best_boxes = i + best_b

print(best_diff, best_boxes)
