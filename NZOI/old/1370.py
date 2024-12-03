N, M, K = map(int, input().split())
S = input()
E = input()
dc = 0

for i in range(len(S)):
    if S[i] != E[i]:
        dc += 1

if dc > K:
    print("IMPOSSIBLE")
else:
    print(f"{dc}")
