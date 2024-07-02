from collections import deque, defaultdict
n = int(input())
strr = input()
vowels = set(["a", "e", "i", "o", "u"])

vowels = defaultdict(str)
cons = defaultdict(str)

for i in range(n):
    if strr[i] in vowels:
        vowels[i] = strr[i]
    else:
        cons[i] = strr[i]

first_vowel_idx = min(vowels)
first_cons_idx = min(cons)

# Duck Latin
if strr[-4:] == "uack": # Begin with Vowel
    tmp = ""
    for i in range(first_cons_idx):
        tmp = tmp + strr[i]
    
if first_cons_idx == 0: # Begin with Cons.
    
