class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long m = points.size(), n = points[0].size();
        vector<long long> oldDp(n + 1, 0);
        vector<long long> newDp(n + 1, 0);

        // dp represents maximum sum when we has processed up to row i
        for (int i = 1; i <= m; ++i) {
            vector<long long> opt(n + 1, 0);

            long long best = 0;
            long long timeSinceBest = 0;
            // absorbing from left
            for (int j = 1; j <= n; ++j) {
                if (best - timeSinceBest <= oldDp[j]) {
                    best = oldDp[j];
                    timeSinceBest = 0;
                }
                opt[j] = max(opt[j], 1LL * best - timeSinceBest);
                ++timeSinceBest;
            }
            
            // right
            best = 0;
            timeSinceBest = 0;
            for (int j = n; j >= 1; --j) {
                if (best - timeSinceBest <= oldDp[j]) {
                    best = oldDp[j];
                    timeSinceBest = 0;
                }
                opt[j] = max(opt[j], 1LL * best - timeSinceBest);
                ++timeSinceBest;
            }

            for (int j = 1; j <= n; ++j) {
                newDp[j] = points[i - 1][j - 1] + opt[j];
            }
            swap(oldDp, newDp);
        }

        return *max_element(oldDp.begin(), oldDp.end());        
    }
};
