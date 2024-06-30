class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [0] * len(nums)
        suffix = [0] * len(nums)
        prefix[0] = nums[0]
        suffix[-1] = nums[-1]

        for index in range(1, len(nums)):
            prefix[index] = nums[index] * prefix[index-1]

        for index in range(len(nums)-2, -1, -1):
            suffix[index] = nums[index] * suffix[index+1]

        answer = [0] * len(nums)
        answer[0] = suffix[1]
        answer[-1] = prefix[-2]

        for i in range(1, len(nums)-1):
            answer[i] = prefix[i-1] * suffix[i+1]
        
        return answer
        