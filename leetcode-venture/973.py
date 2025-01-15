# Own... >__<
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        dtp = defaultdict(list)
        for p in points:
            x, y = p
            dist = (x**2 + y**2) * -1
            dtp[dist].append(p)
        
        dists = list(dtp.keys())
        heapify(dists)
        while len(dists) > k:
            heappop(dists)
        for i in range(len(dists)-1, -1, -1):
            res += dtp[dists[i]]
        while len(res) > k:
            res.pop()
        
        return res

# Model
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        for i in range(len(points)):
            x, y = points[i]
            points[i] = [x**2 + y**2, x, y]
        heapify(points)
        for j in range(k):
            _, x, y = heappop(points)
            res.append([x,y])

        return res
