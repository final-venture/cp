# Own - doesn't pass cuz wrong logic
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        if (nums[-1] + nums[-2]) % 2:
            nums[-1] = [1, False]
        else:
            nums[-1] = [1, True]
        
        for i in range(len(nums)-2, 0, -1):
            if (nums[i] + nums[i-1]) % 2:
                nums[i] = [1, False]
            else:
                nums[i] = [1, True]
            for j in range(i+1, len(nums)):
                if nums[j][1] == nums[i][1]:
                    nums[i][0] = max(nums[i][0], 1 + nums[i+1][0])
            nums[i][0] = max(nums[i][0], nums[i+1][0])
        
        return nums[1][0] + 1

# Model from HTH sajj
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        count = 1
        odd = 0
        even = 0
        
        for i in nums:
            if i % 2 == 0:
                even += 1
            else:
                odd += 1

        for i in range(1, len(nums)):
            if (nums[i] + nums[i-1]) % 2: # if odd
                count += 1
            
        return max(count, odd, even)
