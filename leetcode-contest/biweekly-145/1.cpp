class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        set<int, greater<int>> x(nums.begin(), nums.end());
        for (int i = k - 1; i >= 1; --i)
        {
            if (x.find(i) != x.end())
            {
                return -1;
            }
        }
        for (int i = 100; i > k; --i)
        {
            if (x.find(i) != x.end())
            {
                ++res;
            }
        }
        return res;
    }
};