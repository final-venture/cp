class Solution:
    def minOperations(self, logs: List[str]) -> int:
        count = 0
        for a in logs:
            if a == "../" and count:
                count -= 1
            if a[-2] != ".":
                count += 1
        
        return count
