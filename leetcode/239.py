class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        win = deque()
        l = r = 0

        while r < len(nums):
            if win and l > win[0]:
                win.popleft()
            while win and nums[r] > nums[win[-1]]:
                win.pop()
            win.append(r)

            if (r + 1) >= k:
                res.append(nums[win[0]])
                l += 1
            r += 1
        
        return res
