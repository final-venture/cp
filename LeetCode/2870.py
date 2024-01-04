class Solution:
    def minOperations(self, nums: List[int]) -> int:
        actions = 0

        for i, v in Counter(nums).items():
            if v == 1:
                return -1
            actions += math.ceil(v/3)
        
        return actions
