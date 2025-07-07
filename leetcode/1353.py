class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        max_time = max(ed for st, ed in events)
        curr = 0
        ret = 0
        for time in range(1, max_time + 1):
            while curr < len(events) and events[curr][0] <= time:
                heapq.heappush(pq, events[curr][1])
                curr += 1
            while pq and pq[0] < time:
                heapq.heappop(pq)
            if pq and heapq.heappop(pq) >= time:
                ret += 1

        return ret
