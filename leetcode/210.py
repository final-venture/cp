class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        res = []
        preq = defaultdict(list)
        seeing = set()
        for c, p in prerequisites:
            preq[c].append(p)

        def attempt(c):
            if c in seeing:
                return False
            if not preq[c]:
                return True
            seeing.add(c)
            for x in preq[c]:
                if not attempt(x):
                    return False
            seeing.remove(c)
            res.append(c)
            preq[c] = []
            return True

        for c in range(numCourses):
            if not preq[c]:
                res.append(c)
        for c in range(numCourses):
            if not attempt(c):
                return []
                
        return res 
