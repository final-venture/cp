# Own
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 2:
            return len(s)

        left = 0
        right = 1
        longest = 1
        seen = {s[left]: left}

        while left <= right < len(s):
            if s[right] not in seen:
                seen.update({s[right]: right})
                right += 1
                longest = max(longest, right - left)
            else:
                left = seen[s[right]] + 1
                seen = {s[left]: left}
                right = left + 1

        return longest
        
# Optimal
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) < 2:
            return len(s)

        left = 0
        right = 1
        seen = {s[left]}
        longest = 1

        while left <= right < len(s):
            if s[right] not in seen:
                seen.add(s[right])
                right += 1
                longest = max(longest, right - left)
            else:
                seen.remove(s[left])
                left += 1
        
        return longest
        