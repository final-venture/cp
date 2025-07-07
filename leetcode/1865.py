class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1, self.nums2 = nums1, nums2
        self.freq2 = defaultdict(int)
        for num in nums2:
            self.freq2[num] += 1

    def add(self, index: int, val: int) -> None:
        target_num = self.nums2[index]
        self.freq2[target_num] -= 1
        final_num = target_num + val
        self.nums2[index] = final_num
        self.freq2[final_num] += 1

    def count(self, tot: int) -> int:
        ret = 0
        for num in self.nums1:
            ret += self.freq2[tot - num]
        return ret

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)