class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == k:
            return [max(nums)]

        max_idx = k - 1
        for i in range(k - 1, -1, -1):
            if nums[i] > nums[max_idx]:
                max_idx = i

        res = []
        win = deque()
        for i in range(max_idx, k):
            while win and nums[i] > nums[win[-1]]:
                win.pop()
            win.append(i)
        res.append(nums[win[0]])
        l, r = 1, k

        while r < len(nums):
            if l > win[0]:
                win.popleft()
            while win and nums[r] > nums[win[-1]]:
                win.pop()
            win.append(r)
            res.append(nums[win[0]])
            l += 1
            r += 1
        
        return res
