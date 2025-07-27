#define ll long long
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int nn = conflictingPairs.size();
        for (auto& v : conflictingPairs) {
            if (v[0] > v[1]) {
                swap(v[0], v[1]);
            }
        }
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });

        ll total_subs = (1LL * n * n + n) / 2;
        ll profit = 0, max_profit = 0, max1 = 0, max2 = 0, blocked = 0;

        for (int i = 0; i < nn; ++i) {
            int start = conflictingPairs[i][0];
            int top = conflictingPairs[i][1];
            int bottom = (i < nn - 1) ? conflictingPairs[i + 1][1] : n + 1;
            int gap = bottom - top;

            if (start >= max1) {
                max2 = max1;
                max1 = start;
                profit = 0;
            }
            else if (start > max2) {
                max2 = start;
            }

            blocked += gap * max1;
            profit += gap * (max1 - max2);
            max_profit = max(profit, max_profit);
        }

        return total_subs - blocked + max_profit;
    }
};