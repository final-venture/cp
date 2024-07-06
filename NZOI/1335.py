N = int(input())
start = gap = N // 2
route = []

if N % 2:
    for i in range(1, N+1, gap):
        route.append(i)
    for i in range(start, 1, -1):
        route.append(i)
        route.append(i+gap)
else:
    for i in range(start, 0, -1):
        route.append(i)
        route.append(i + gap)

print(" ".join(map(str, route)))
