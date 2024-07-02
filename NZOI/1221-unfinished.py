count_vowels = count_cons = 0
vowels = set(["a", "e", "i", "o", "u"])
lf = set(["l", "f"])
n = int(input())
strr = input()

for i, v in enumerate(strr):
    if v in vowels:
        count_vowels += 1
    else:
        count_cons += 1

def gnv(strr, n): # Goose no vowel
    if strr.endswith("onk") and count_vowels == 1 and strr != "onk":
        return 1
    return 0

def d(strr, n):
    res = 0
    if strr.endswith("ck"): # Duck
        if strr.endswith("uack"): # Duck cons start
            if count_vowels == 2 and strr != "uack":
                return 1
            if strr[0] in vowels:
                for i in range(n - 5, -1, -1):
                    if strr[i] in vowels:
                        return res
                    res += 1                    
        else: # Duck vowel start
            if count_cons == 2 and strr != "ck":
                return 1
            if strr[0] not in vowels:
                for i in range(n - 3, -1, -1):
                    if strr[i] not in vowels:
                        return res
                    res += 1                    
    return 0

def gv(strr, n):
    if count_vowels > 1:
        curr = 0
        while curr < n:
            if strr[curr] in vowels:
                if curr + 3 >= n:
                    return 0
                if strr[curr+1] == "l" and strr[curr+2] == "f" and strr[curr+3] == strr[curr]:
                    curr += 4
                    if curr >= n:
                        return 1
                else:
                    return 0
            else:
                if curr == n - 1:
                    return 1
                curr += 1
    return 0

print(gnv(strr, n) + gv(strr, n) + d(strr, n))
