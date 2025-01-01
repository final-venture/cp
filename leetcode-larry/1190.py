class Solution:
    def reverseParentheses(self, s: str) -> str:
        # Brute force: TC: O(n^2), MC: O(n)
        p_i = []
        res = []

        for c in s:
            if c == "(":
                p_i.append(len(res))
            elif c == ")":
                start_i = p_i.pop()
                res[start_i:] = res[start_i:][::-1]
            else:
                res.append(c)

        return "".join(res)
