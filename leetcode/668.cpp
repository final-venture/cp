class Solution {
private:
    int m, n, k;
public:
    bool ok(int x)
    {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
        {
            cnt += min(x / i, n);
            if (cnt >= k) break;
        }
        return (cnt < k);
    }
    int findKthNumber(int m, int n, int k) {
        this -> m = m; this -> n = n; this -> k = k;
        int l = 1, r = m * n;
        while (l < r)
        {
            int m = l + ((r - l) >> 1);
            if (ok(m))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
