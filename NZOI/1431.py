N = int(input())

for _ in range(N):
    rev = False
    x, y = map(int, input().split())
    if x % 2:
        rev = True
    if rev:
        if y % 2:
            print("BLACK")
        else:
            print("WHITE")
    else:
        if y % 2:
            print("WHITE")
        else:
            print("BLACK")
