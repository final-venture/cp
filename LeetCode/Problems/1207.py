class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        data = [0] * 2001
        s = set()

        for i in arr:
            data[i] += 1

        for i in data:
            if i in s:
                return False
            if i != 0:
                s.add(i)
        
        return True
