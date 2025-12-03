class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        maxx = 10**9
        m2c = defaultdict(list) # gradient to list of y intercepts
        mid2m = defaultdict(list) # midpoint of line to its slope
        n = len(points)

        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                if x2 - x1 == 0:
                    m = maxx
                    c = x1
                else:
                    m = (y2 - y1) / (x2 - x1)
                    c = round(y1 - m*x1, 6) # y - y1 = m(x - x1) ==> y - y1 = mx - m*x1 ==> y = mx + (y1- m*x1)
                m2c[m].append(c)
                mid = (x1+x2)*100000+y1+y2
                mid2m[mid].append(m)
        
        # print(m2c)

        ret = 0
        for m, c_list in m2c.items():
            pfx = 0
            cnt_by_c = defaultdict(int)
            for c in c_list:
                cnt_by_c[c] += 1
            # print(m, cnt_by_c)
            for cnt in cnt_by_c.values():
                # print(pfx*cnt)
                ret += pfx * cnt
                pfx += cnt
        
        for mid, m_list in mid2m.items():
            pfx = 0
            cnt_by_m = defaultdict(int)
            for m in m_list:
                cnt_by_m[m] += 1
            for cnt in cnt_by_m.values():
                ret -= pfx * cnt
                pfx += cnt

        return ret
