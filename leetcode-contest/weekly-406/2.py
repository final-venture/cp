class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort()
        verticalCut.sort()
        res = 0

        sv = sum(verticalCut)
        sh = sum(horizontalCut)

        while horizontalCut and verticalCut:
            if horizontalCut[-1] > verticalCut[-1]:
                x = horizontalCut.pop()
                res += (x + sv)
                sh -= x
            else:
                x = verticalCut.pop()
                res += (x + sh)
                sv -= x

        for c in horizontalCut:
            res += c
        for c in verticalCut:
            res += c

        return res
