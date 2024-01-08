class TimeMap:

    def __init__(self):
        self.map = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.map[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        left = 0
        right = len(self.map[key]) - 1
        i = 0

        while left <= right:
            mid = (left + right) // 2
            if self.map[key][mid][-1] < timestamp:
                left = mid + 1
                i = max(i, mid)
            elif self.map[key][mid][-1] > timestamp:
                right = mid - 1
            else:
                return self.map[key][mid][0]
        
        if self.map[key] and self.map[key][i][-1] < timestamp:
            return self.map[key][i][0]
        return ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
