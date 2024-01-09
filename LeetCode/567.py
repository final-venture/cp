class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        if len(s2) < len(s1):
            return False

        left = 0
        s1letters = defaultdict(int)
        s2letters = defaultdict(int)

        for letter in s1:
            s1letters[letter] += 1
        for letter in s2[:len(s1)]:
            s2letters[letter] += 1
        if s2letters == s1letters:
            return True

        for right in range(len(s1), len(s2)):
            if s2letters != s1letters:
                s2letters[s2[left]] -= 1
                if s2letters[s2[left]] == 0:
                    s2letters.pop(s2[left])
                left += 1
                s2letters[s2[right]] += 1

            if s2letters == s1letters:
                return True
        
        return False
