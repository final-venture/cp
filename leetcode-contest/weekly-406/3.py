class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        cost = 0
        cost2 = 0
        for i in horizontalCut:
            cost += i*n
        for i in verticalCut:
            cost += i

        for i in verticalCut:
            cost2 += i*m
        for i in horizontalCut:
            cost2 += i

        return min(cost, cost2)
        