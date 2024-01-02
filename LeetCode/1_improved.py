class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hash_table = {}
        for i in range(len(nums)):
            complement = target - nums[i]
                
            if complement not in hash_table:
                hash_table.update({nums[i]: i})
            else:    
                return [i, hash_table[complement]]
            