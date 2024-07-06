X, Y, A, B = map(int, input().split())

maxh = (X//A) * (Y//B)
maxv = (X//B) * (Y//A)
maxx = max(maxh, maxv)

print(maxx)
