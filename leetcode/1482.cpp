class Solution {
private:
    vector<int> bloomDay;
    int m;
    int k;
public:
    int check(int d)
    {
        int ok = 0;
        int csc = 0;
        for (int x : bloomDay)
        {
            if (x <= d)
            {
                ++csc;
                if (csc >= k)
                {
                    ++ok;
                    csc = 0;
                }
            }
            else
            {
                csc = 0;
            }
        }
        return ok;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n / k < m) return -1;
        this -> bloomDay = bloomDay; this -> m = m; this -> k = k;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid) >= m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
