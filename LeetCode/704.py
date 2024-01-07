class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binarysearch(left, right, target):
            middle = (left+right) // 2
            if left <= right:
                if nums[middle] < target:
                    return binarysearch(middle+1, right, target)
                elif nums[middle] > target:
                    return binarysearch(left, middle-1, target)
                else:
                    return middle
            return -1

        return binarysearch(0, len(nums) - 1, target)
