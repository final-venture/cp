class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> x(banned.begin(), banned.end());
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (x.find(i) != x.end()) continue;
            if (maxSum - i < 0) break;
            maxSum -= i;
            ++cnt;
        }
        return cnt;
    }
};