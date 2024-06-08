# Own
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        schars = {}
        tchars = {}
        for letter in s:
            schars[letter] = (schars.get(letter, 0) + 1)
        for letter in t:
            tchars[letter] = (tchars.get(letter, 0) + 1)

        if schars == tchars:
            return True
        else:
            return False
        
# Optimal
class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        char_map = [0] * 26

        for i in range(len(s)):
            char_map[ord(s[i]) - ord('a')] += 1
            char_map[ord(t[i]) - ord('a')] -= 1

        return all(count == 0 for count in char_map)
    
