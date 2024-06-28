class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heapify(nums)
        while len(nums) > k:
            heappop(nums)
        return nums[0]

# Can also use Quickselect: https://www.youtube.com/watch?v=XEmy13g1Qxc
