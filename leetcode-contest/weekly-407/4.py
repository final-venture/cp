class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        diff = [nums[i] - target[i] for i in range(len(nums))]
        res = 0
        last = 0

        for d in diff:
            if d > 0:
                if last < d:
                    res += min(d, d - last)
            elif d < 0:
                if last > d:
                    res += min(-d, last - d)
            last = d

        return res
