class Solution:
    def climbStairs(self, n: int) -> int:
        data = [1, 2]
        
        for i in range(n):
            if i < 2:
                continue
            data.append(data[-1] + data[-2])
        
        return data[n-1]
