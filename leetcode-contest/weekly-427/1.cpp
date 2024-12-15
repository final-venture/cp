class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            int cand = i + nums[i];
            int idx = ((cand % n) + n) % n;
            res[i] = nums[idx];
        }
        return res;
    }
};