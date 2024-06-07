N = int(input())
abc = []
res = 0

for i in range(N):
    abc.append(int(input()))

abc.sort(reverse=True)

for i in range(len(abc)):
    if abc[i] != abc[i-1] or i == 0:
        res += 1

print(res)
