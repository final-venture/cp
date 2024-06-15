A, B, K = map(int, input().split())
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return abs(a * b) // gcd(a, b) 

lcm = lcm(A, B)
small = min(A, B)
big = max(A, B)

r = K
u_big = u_small = u_lcm = 0

q_lcm = lcm * (r // lcm)
r -= q_lcm
u_lcm = q_lcm // big

if r % small == 0 and r % big != 0:
    q_small = small * (r // small)
    r -= q_small
    u_small = q_small // small
else:
    q_big = big * (r // big)
    r -= q_big
    u_big = q_big // big

    q_small = small * (r // small)
    r -= q_small
    u_small = q_small // small

u_total = u_big + u_small + u_lcm

if r <= small / 2 or r == 0:
    print(f"{r} {u_total}")
else:
    print(f"{abs(r-small)} {u_total+1}")
