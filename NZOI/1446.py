d, bp_i, tp = map(int, input().split())

prices = list(map(int, input().split()))

last = -1
l = 0
r = 1
bp = bp_i
valid = False

while l < len(prices) - 1:
    if not valid:
        if r >= len(prices):
            l += 1
            r = l + 1
            continue
        if prices[l] < prices[r] and prices[l] <= tp and prices[l] <= bp:
            valid = True
        else:
            r += 1
    else:
        for i in range(l - last - 1):
            print("WAIT")
        last = r
        sb = divmod(bp, prices[l])[0]
        bp -= (sb * prices[l])
        print(f"BUY {sb}")
        for i in range(r - l - 1):
            print("HOLD")
        print(f"SELL {sb}")
        bp += (sb * prices[r])
        l = r + 1
        r = l + 1
        valid = False

for i in range(len(prices) - 1 - last):
    print("WAIT")
print(f"{bp - bp_i}")
