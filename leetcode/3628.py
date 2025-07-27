class Solution:
    def numOfSubsequences(self, s: str) -> int:
        # try inserting L, C, and T separately
        # at each index i store the number of l, c, t seen inclusive 
        trimmed = ""
        for c in s:
            if c in ["L", "C", "T"]:
                trimmed += c
        n = len(trimmed)

        dp_l = [0] * (n + 1)
        l_cnt = lc_cnt = total_cnt = 0
        for i in range(n):
            dp_l[i + 1] = dp_l[i]
            if trimmed[i] == 'L':
                dp_l[i + 1] = dp_l[i] + 1
            elif trimmed[i] == "C":
                lc_cnt += dp_l[i + 1]
            elif trimmed[i] == "T":
                total_cnt += lc_cnt

        sfx_t = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            sfx_t[i] = sfx_t[i + 1]
            if trimmed[i] == 'T':
                sfx_t[i] = sfx_t[i + 1] + 1

        # print(sfx_t)
        
        # add t will lead to lc_cnt profit
        max_profit = lc_cnt
        #add c
        for i in range(n):
            max_profit = max(max_profit, sfx_t[i] * dp_l[i + 1])

        t_cnt = ct_cnt = 0
        for i in range(n - 1, -1, -1):
            if trimmed[i] == 'T':
                t_cnt += 1
            elif trimmed[i] == 'C':
                ct_cnt += t_cnt

        max_profit = max(max_profit, ct_cnt)
        # print(ct_cnt, lc_cnt)
        return max_profit + total_cnt
        #add l
        
        
        # LCLCT
        # LLCCT
        # LCCCT
        # LCCTT
        