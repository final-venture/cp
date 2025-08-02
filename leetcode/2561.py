class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        freq1 = defaultdict(int)
        freq2 = defaultdict(int)
        for f in basket1:
            freq1[f] += 1
        for f in basket2:
            freq2[f] += 1
        
        to_move1 = []
        to_move2 = []

        for fruit, freq in freq1.items():
            if ((freq1[fruit] + freq2[fruit]) & 1):
                return -1
            if freq1[fruit] > freq2[fruit]:
                qty2move = freq1[fruit] - (freq1[fruit] + freq2[fruit]) // 2
                to_move1.append([fruit, qty2move])
        for fruit, freq in freq2.items():
            if ((freq1[fruit] + freq2[fruit]) & 1):
                return -1
            if freq2[fruit] > freq1[fruit]:
                qty2move = freq2[fruit] - (freq2[fruit] + freq1[fruit]) // 2
                to_move2.append([fruit, qty2move])
        
        dq1 = deque(sorted(to_move1))
        dq2 = deque(sorted(to_move2))

        indirect_swap_cost = 2 * min(basket1 + basket2)
        ret = 0
        while dq1:
            cost = min(dq1[0][0], dq2[-1][0])
            if cost > indirect_swap_cost:
                cost = indirect_swap_cost
            dq1[0][1] -= 1
            if (dq1[0][1] == 0):
                dq1.popleft()
            dq2[-1][1] -= 1
            if (dq2[-1][1] == 0):
                dq2.pop()
            ret += cost

        return ret
        