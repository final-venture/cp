class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def bs(left, right):
            mid = (left + right) // 2
            if left <= right:
                if nums[mid] == target:
                    return mid
                if nums[mid] < target:
                    return bs(left+1, right)
                else:
                    return bs(left, right-1)
            return -1
    
        def find_pivot(left, right):
            pivot = len(nums) - 1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] < nums[0]:
                    right = mid - 1
                    pivot = min(pivot, mid)
                else:
                    left = mid + 1
            return pivot
        
        if nums[0] <= nums[-1]:
            return bs(0, len(nums) - 1)
        else:
            pivot = find_pivot(0, len(nums) - 1)
            if target < nums[0]:
                return bs(pivot, len(nums) - 1)
            if target > nums[0]:
                return bs(0, pivot)
            else:
                return 0
