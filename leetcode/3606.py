class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        vbt = ["electronics", "grocery", "pharmacy", "restaurant"]
        alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"
        alph_set = set(alph)
        ret = []

        def valid(code):
            if not code:
                return False
            for i in range(len(code)):
                if code[i] not in alph_set:
                    return False
            return True

        for category in vbt:
            cand = []
            for i in range(len(code)):
                if businessLine[i] == category and valid(code[i]) and isActive[i]:
                    cand.append(code[i])
            ret += sorted(cand)

        return ret
