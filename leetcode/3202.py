class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        nums = [num%k for num in nums]
        maxx = 0

        for i in range(k):
            l = [0] * k
            ok = [True] * k #ok means want alternation (not i)
            for num in nums:
                if num == i:
                    for j in range(k):
                        if ok[j]:
                            l[j] += 1
                            if i != j:
                                ok[j] = False
                else:
                    if not ok[num]:
                        l[num] += 1
                        ok[num] = True
            maxx = max(maxx, max(l))
        
        return maxx
