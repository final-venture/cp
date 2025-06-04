class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [&](vector<int>& v1, vector<int>& v2)
        {
            return (v1[0] < v2[0]);
        });
        vector<int> sfx(n + 1); sfx[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            sfx[i] = max(sfx[i + 1], events[i][2]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int s = events[i][0]; int e = events[i][1]; int v = events[i][2];
            int l = 0; int r = n;
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (events[m][0] <= e)
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            res = max(res, v + sfx[l]);
        }
        return res;
    }
};
