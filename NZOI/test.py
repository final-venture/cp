from collections import deque
stitches = deque()
for i in range(6):
    stitches.append(0) # Add the six initial stitches in row 0
n = int(input())
for i in range(n):
    instruction = input()
    kind = instruction[0]
    x = int(instruction[1:])
    if kind == 'I':
        row = stitches.popleft()
        for i in range(x):
            stitches.append(row + 1)
    else:
        max_row = 0
        for i in range(x):
            max_row = max(max_row, stitches.popleft())
        stitches.append(max_row + 1)
    # print(stitches)

print(len(stitches))
print(stitches.pop()) # Get youngest element
