class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while right > left:
            while not s[left].isalnum() and left < right:
                left += 1
            while not s[right].isalnum() and right > left:
                right -= 1
            if s[left].lower() != s[right].lower():
                return False
            right -= 1
            left += 1
        
        return True
