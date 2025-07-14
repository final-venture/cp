class Solution:
    def processStr(self, s: str) -> str:
        ret = ""
        for c in s:
            if c == '*':
                ret = ret[:-1]
            elif c == '#':
                for i in range(len(ret)):
                    ret += ret[i]
            elif c == '%':
                tmp = ""
                for i in range(len(ret) - 1, -1, -1):
                    tmp += ret[i]
                ret = tmp
            else:
                ret += c
        return ret
