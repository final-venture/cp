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
        