class Solution:
    def countSeniors(self, details: List[str]) -> int:
        res = 0
        for x in details:
            age = x[11:-2]
            if int(age) > 60:
                res += 1

        return res
