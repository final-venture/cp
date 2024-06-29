# Own - Doesn't pass on new testcase 80
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        d2a = defaultdict(list)
        res = ["JFK"]

        tickets.sort(key=lambda x:x[1])
        for d, a in tickets:
            d2a[d].append(a)

        def travel(l):
            if len(res) == len(tickets) + 1:
                return True
            for i in range(len(d2a[l])):
                if d2a[l][i]:
                    tmp = d2a[l][i]
                    d2a[l][i] = None
                    res.append(tmp)
                    if travel(tmp):
                        return True
                    res.pop()
                    d2a[l][i] = tmp 

        travel("JFK")
        return res

# Eulerian Path/Circuit algorithm (Hierholzer's algorithm) https://www.youtube.com/watch?v=8MpoO2zA2l4
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        d2a = defaultdict(list)
        res = []

        tickets.sort(reverse=True)
        for d, a in tickets:
            d2a[d].append(a)

        def travel(l):
            while d2a[l]:
                travel(d2a[l].pop())
            res.append(l)

        travel("JFK")
        return res[::-1]
