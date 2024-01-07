class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
                for j in range(len(nums)):
                    if j != i and nums[j] + nums[i] == target:
                        return [j, i]
                    