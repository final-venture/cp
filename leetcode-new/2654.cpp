class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c = count(nums.begin(), nums.end(), 1);
        if (c) return n - c;

        int ret = 2e6;
        for (int i = 0; i < n; ++i)
        {
            // no point of gcd'ing one pair more than once.
            // brute all pairs.
            int g = nums[i];
            for (int j = i + 1; j < n; ++j)
            {
                g = gcd(g, nums[j]);
                if (g == 1)
                {
                    ret = min(ret, j - i + (n - 1));
                    break; // break when we find nearest dist pair of every starting i.
                }
            }
        }
        return (ret == 2e6) ? -1 : ret;
    }
};
