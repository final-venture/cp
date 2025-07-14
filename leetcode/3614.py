class Solution:
    def processStr(self, s: str, k: int) -> str:
        # Find the length of final string
        final_len = 0
        for c in s:
            if c == '#':
                final_len *= 2
            elif c == '%':
                continue
            elif c == '*':
                final_len = max(0, final_len - 1)
            else:
                final_len += 1
        
        if k >= final_len or k < 0:
            return '.'

        # Go backwards
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c == '#':
                final_len /= 2
                if k >= final_len:
                    k -= final_len
            elif c == '%':
                k = final_len - 1 - k
            elif c == '*':
                final_len += 1
            else:
                if k == final_len - 1:
                    return c    
                final_len -= 1

        return '.'
