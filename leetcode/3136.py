class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False

        alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        nums = "0123456789"
        vowels = "AEIOUaeiou"
        
        has_vowel = False
        has_consonant = False

        for c in word:
            if c not in alpha and c not in nums:
                return False
            if c in vowels:
                has_vowel = True
            if (c not in vowels) and (c not in nums):
                has_consonant = True

        if has_vowel and has_consonant:
            return True
        return False
