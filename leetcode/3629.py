class Solution:
    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0

        maxx = max(nums)

        spf = list(range(maxx + 1))
        for i in range(2, int(maxx**0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, maxx + 1, i):
                    if spf[j] == j:
                        spf[j] = i


        def get_pf(num):
            factors = set()
            while num > 1:
                factor = spf[num]
                factors.add(factor)
                while num % factor == 0:
                    num //= factor
            return factors

        p2i = defaultdict(list)
        for i, num in enumerate(nums):
            if num > 1:
                for p in get_pf(num):
                    p2i[p].append(i)

        queue = deque([(0, 0)])
        visited = {-1}
        visited.add(0)

        while queue:
            curr_idx, dist = queue.popleft()
            if curr_idx == n - 1:
                return dist

            for next_idx in [curr_idx - 1, curr_idx + 1]:
                if 0 <= next_idx < n and next_idx not in visited:
                    visited.add(next_idx)
                    queue.append((next_idx, dist + 1))

            val = nums[curr_idx]
            if val > 1 and spf[val] == val:
                p = val
                if p in p2i:
                    for next_idx in p2i[p]:
                        if next_idx not in visited:
                            visited.add(next_idx)
                            queue.append((next_idx, dist + 1))
                if p2i[p]:
                    del p2i[p]

        return -1