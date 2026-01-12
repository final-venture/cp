class Solution
{
public:
    int maximumAND(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        int ret = 0;
        uint32_t maxNum = *max_element(nums.begin(), nums.end()) + k / m;
        int maxBit = bit_width(maxNum);
        vector<int> req(n);
        for (int i = maxBit - 1; i >= 0; --i)
        {
            int cand = ret | (1 << i);
            for (int j = 0; j < n; ++j)
            {
                uint32_t firstMismatch = cand & ~nums[j];
                int maxBit2 = bit_width(firstMismatch);
                int mask = (1LL << maxBit2) - 1;
                req[j] = (mask & cand) - (mask & nums[j]);
            }
            sort(req.begin(), req.end());
            long long summ = 0;
            for (int j = 0; j < m; ++j)
            {
                summ += req[j];
            }
            if (summ <= k)
            {
                ret = cand;
            }
        }
        return ret;
    }
};
