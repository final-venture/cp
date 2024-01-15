class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        a = defaultdict(int)
        b = set()
        res1 = []
        res2 = []

        for i in matches:
            a[i[1]] += 1
            for j in i:
                b.add(j)

        for i in b:
            if a[i] == 0:
                res1.append(i)
            if a[i] == 1:
                res2.append(i)
        
        return [sorted(res1), sorted(res2)]
