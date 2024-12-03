stchs = "000000"
curr = 0
maxx = 0

def execute(cmd):
    global stchs, curr
    inst, qty = cmd[0], int(cmd[1:])

    if inst == "I":
        nxt_row = int(stchs[curr]) + 1
        stchs = stchs[0:curr] + str(nxt_row) * qty + stchs[curr+1:]
        nxt_idx = (curr + qty) % len(stchs)
        curr = nxt_idx
    else:
        frm = curr
        last_idx = (curr + qty - 1) % len(stchs)
        to = (curr + qty) % len(stchs)
        if curr + qty > len(stchs):
            stchs = str(int(stchs[last_idx]) + 1) + stchs[to:frm]
            curr = 1 % len(stchs)
        else:
            stchs = stchs[0:frm] + str(int(stchs[last_idx]) + 1) + stchs[(frm+qty):]
            curr = (curr + 1) % len(stchs)

        
for i in range(int(input())):
    execute(input())
    # print(stchs)

for i in range(len(stchs)):
    maxx = max(maxx, int(stchs[i]))
print(len(stchs))
print(maxx)
