class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        ret = 0
        if costBoth < cost1 + cost2 and need1 > 0 and need2 > 0:
            mini = min(need1, need2)
            ret += costBoth * mini
            need1 -= mini
            need2 -= mini
        
        if need1 > 0:
            if costBoth < cost1:
                ret += costBoth * need1
                need2 -= need1
            else:
                ret += cost1 * need1
            
        if need2 > 0:
            ret += min(costBoth, cost2) * need2

        return ret
