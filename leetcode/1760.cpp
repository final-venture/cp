class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int ops = 0;
            for (int n : nums)
            {
                ops += (n - 1) / m;
                if (ops > maxOperations) break;
            }
            if (ops <= maxOperations)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};
