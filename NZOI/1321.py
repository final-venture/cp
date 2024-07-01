stchs = "000000"
curr = 0
last = 0

def execute(strr):
    global stchs, curr, last
    action, qty = strr[0], int(strr[1:])

    if action == "I":
        last = int(stchs[curr]) + 1
        stchs = stchs[:curr] + str(last) * qty + stchs[curr+1:]
        curr = (curr + qty) % len(stchs)
    if action == "D":
        idxl = (curr + qty - 1) % len(stchs)
        last = int(stchs[idxl]) + 1
        if curr + qty <= len(stchs):
            stchs = stchs[:curr] + str(last) + stchs[curr+qty:]
            curr = (curr + 1) % len(stchs)
        else:
            stchs = str(last) + stchs[idxl+1:curr]
            curr = 1 % len(stchs)

for i in range(int(input())):
    execute(input())
    print(curr)
    print(stchs)

print(len(stchs))
print(last)

# 1111000
   #h

   #2  
