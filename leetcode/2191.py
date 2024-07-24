class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        n2j = {}
        counts = defaultdict(int)
        res = []

        mapping = [str(m) for m in mapping]
        nums = [str(num) for num in nums]
        
        for x in nums:
            counts[int(x)] += 1
            cand = ""
            for c in x:
                cand += mapping[int(c)]
            n2j[int(x)] = int(cand)
        
        tmp = list(n2j.items())
        tmp.sort(key=lambda x:x[1])

        for x in tmp:
            while counts[x[0]]:
                res.append(x[0])
                counts[x[0]] -= 1
        
        return res
