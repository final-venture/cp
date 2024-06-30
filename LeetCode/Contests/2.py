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

test = Solution()
print(test.maximumLength([1,2,1,1,2,1,2]))
