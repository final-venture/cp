class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mpp;
        int prev = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == n || s[i] != s[i - 1])
            {
                int sz = i - prev;
                ++mpp[s.substr(prev, sz)];
                if (sz >= 2)
                {
                    mpp[s.substr(prev, sz - 1)] += 2;
                }
                if (sz >= 3)
                {
                    mpp[s.substr(prev, sz - 2)] += 3;
                }
                prev = i;
            }
        }
        int ret = -1;
        for (auto& [s, c] : mpp)
        {
            if (c >= 3)
            {
                int nn = s.size();
                ret = max(ret, nn);
            }
        }
        return ret;
    }
};
