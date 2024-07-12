class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        # Brute Force: TC: O(n^2), MC: O(n)
        order = ["ab", "ba"] if x > y else ["ba", "ab"]
        res = 0

        for seq in order:
            stack = ["#"]
            pts = x if seq == "ab" else y
            for i, c in enumerate(s):
                stack.append(c)
                if stack[-2] + stack[-1] == seq:
                    res += pts
                    stack.pop()
                    stack.pop()
            s = "".join(stack[1:])
        
        return res
