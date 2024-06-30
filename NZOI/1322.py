n = int(input())
brnchs = input().split(" ")

total = 0
for x in brnchs:
    total += int(x)

rem = total % n
if not rem:
    print(0)
else:
    print(n-rem)
