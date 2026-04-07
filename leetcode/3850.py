class Solution:
    def f235(self, k):
        t2 = t3 = t5 = 0
        while k % 3 == 0:
            k = k // 3
            t3 += 1
        while k % 2 == 0:
            k = k // 2
            t2 += 1
        while k % 5 == 0:
            k = k // 5
            t5 += 1

        if k != 1:
            return (-10000, -10000, -10000)
        else:
            return (t2, t3, t5)

    def countSequences(self, nums: List[int], k: int) -> int:
        k_fact = self.f235(k)
        if k_fact == (-10000, -10000, -10000):
            return 0

        n = len(nums)
        nums_fact = [self.f235(num) for num in nums]

        @cache
        def dfs(idx, fact):
            if idx >= n:
                if fact == k_fact:
                    return 1
                return 0
            ret = 0
            for op in range(-1, 2):
                new_fact = (fact[0] + op * nums_fact[idx][0], 
                            fact[1] + op * nums_fact[idx][1], 
                            fact[2] + op * nums_fact[idx][2])
                ret += dfs(idx + 1, new_fact)
            return ret
            
        return dfs(0, (0, 0, 0))
    