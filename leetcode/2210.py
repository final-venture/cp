class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        n = len(nums)
        hill_started = valley_started = False
        hillcnt = valleycnt = 0
        for i in range(1, n - 1):
            if nums[i - 1] < nums[i]:
                hill_started = True
            if nums[i] > nums[i + 1] and hill_started:
                hill_started = False
                hillcnt += 1
            if nums[i - 1] > nums[i]:
                valley_started = True
            if nums[i] < nums[i + 1] and valley_started:
                valley_started = False
                valleycnt += 1
        
        return valleycnt + hillcnt
