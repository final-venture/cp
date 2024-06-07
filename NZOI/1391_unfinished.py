parsed = input().split(" ")

def xd():
    A, B, K = int(parsed[0]), int(parsed[1]), int(parsed[2])
    res = 0

    l = max(A, B)
    s = min(A, B)

    if K >= l:
        l_req = K // l
        K = K - l_req * l
        res += l_req

    
    return res + 1 if abs(K - s) < abs(K) else res

print(xd())
