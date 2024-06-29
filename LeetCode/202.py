class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        def test(num):
            if num in seen:
                return False
            if num == 1:
                return True
            seen.add(num)
            res = 0
            strr = str(num)
            for i in range(len(strr)):
                res += int(strr[i]) ** 2
            return test(res)
        
        return test(n)
