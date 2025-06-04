class Solution {
public:
    vector<int> Z(vector<int>& a)
    {
        int nn = a.size();
        vector<int> z(nn);
        int l = 0, r = 0;
        for (int k = 1; k < nn; ++k)
        {
            if (k < r) // if k is in z-box
            {
                z[k] = min(r - k, z[k - l]);
            }
            while (k + z[k] < nn && a[z[k]] == a[k +  z[k]])
            {
                ++z[k];
            }
            if (k + z[k] > r)
            {
                l = k;
                r = k + z[k];
            }
        }
        return z;
    }
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> z1 = Z(nums);
        int cnt = 0;
        for (int i = 1; i < n; ++i)
        {
            vector<int> cand(nums.begin() + i, nums.end());
            vector<int> z2 = Z(cand);
            for (int j = i + 1; j < n; ++j)
            {
                if ((j >= i + i && z1[i] >= i) || (z2[j - i] >= j - i))
                {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
