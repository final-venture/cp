class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(500005, 0);
        for (int i = 0; i < n; ++i)
        {
            int s = nums[i] - k + 222222;
            int e = nums[i] + k + 222222 + 1;
            ++a[s];
            --a[e];
        }
        int ret = 1;
        for (int i = 1; i < 500005; ++i)
        {
            a[i] = a[i - 1] + a[i];
            ret = max(ret, a[i]);
        }
        return ret;
    }
};
