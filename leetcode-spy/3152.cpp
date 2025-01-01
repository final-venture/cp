class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int LOG = 17;
        int n = nums.size();
        if (n == 1) {
            vector<bool> ret;
            for (auto& q : queries)
                ret.push_back(true);
            return ret;
        }

        vector<int> pfx(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            pfx[i] = ((nums[i] % 2) != (nums[i + 1] % 2));
        }
        vector<vector<int>> sparse(n - 1, vector<int>(LOG));
        for (int i = 0; i < n - 1; ++i)
        {
            sparse[i][0] = pfx[i];
        }
        for (int j = 1; (1 << j) <= n - 1; ++j)
        {
            for (int i = 0; i + (1 << j) - 1 < n - 1; ++i)
            {
                sparse[i][j] = (sparse[i][j - 1] & sparse[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<bool> ret;
        for (auto& q : queries)
        {
            int l = q[0], r = q[1];
            if (l == r)
            {
                ret.push_back(true);
                continue;
            }

            int diff = r - l;
            int j = log2(diff);
            ret.push_back(sparse[l][j] & sparse[r - (1 << j)][j]);
        }
        return ret;
    }
};