class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])

        a = nums.copy()
        b = nums.copy()

        a[-1] = 0
        b[0] = 0
        b.append(0)

        for i in range(len(a)-4, -1, -1):
            a[i] += max(a[i+2], a[i+3])

        for i in range(len(b)-4, 0, -1):
            b[i] += max(b[i+2], b[i+3])

        return max(max(a[0], a[1]), max(b[1], b[2]))
