class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums.pop()
        while nums:
            res = nums.pop() ^ res

        return res
