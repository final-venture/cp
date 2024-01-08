class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        res = nums[0]

        if nums[0] < nums[-1]:
            return res

        while left <= right:

            mid = (left + right) // 2
            res = min(res, nums[mid])

            if nums[mid] < nums[0]:
                right = mid - 1

            else:
                left = mid + 1

        return res
