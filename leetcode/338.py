class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0]
        bp = 1
        
        for i in range(1, n + 1):
            new_bp = bp * 2
            if i == new_bp:
                bp = new_bp
            dp.append(1)
            dp[i] += dp[i-bp]
        
        return dp
