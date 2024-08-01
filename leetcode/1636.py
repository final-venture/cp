class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        fc = defaultdict(int)
        res = []
        for x in nums:
            fc[x] += 1

        hs = list(fc.items())
        hs.sort(key=lambda x:(x[1],-x[0]))
        for n, c in hs:
            res += [n] * c
        
        return res
