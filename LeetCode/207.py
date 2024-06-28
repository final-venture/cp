# Own
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        self.res = True
        preq = defaultdict(list)
        attempted = set()
        taken = set()
        
        for c, p in prerequisites:
            preq[c].append(p)

        def attempt(c):
            if self.res == False or c in taken:
                return
            if c in attempted and c not in taken:
                self.res = False
            attempted.add(c)
            for p in preq[c]:
                attempt(p)
            taken.add(c)

        for c in range(numCourses):
            attempt(c)

        return self.res

# Optimal
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
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
            preq[c] = []
            return True

        for c in range(numCourses):
            if not attempt(c):
                return False
        
        return True
