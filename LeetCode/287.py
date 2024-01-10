# FLOYD'S TURTLE AND HARE ALGORITHM

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = 0
        fast = 0
        while slow != fast or slow == fast == 0:
            slow = nums[slow]
            fast = nums[nums[fast]]

        slow2 = 0
        while slow2 != slow:
            slow2 = nums[slow2]
            slow = nums[slow]

        return slow
