class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) < 2:
            return len(s)

        left = 0
        right = 1
        seen = [0] * 26
        seen[ord(s[left]) - ord("A")] += 1
        res = 0

        while left <= right < len(s):
            if sum(seen) - max(seen) <= k:
                seen[ord(s[right]) - ord("A")] += 1
                right += 1
            else:
                seen[ord(s[left]) - ord("A")] -= 1
                left += 1
            if sum(seen) - max(seen) <= k:
                res = max(sum(seen), res)
            else:
                res = max(sum(seen) - 1, res)

        return res
