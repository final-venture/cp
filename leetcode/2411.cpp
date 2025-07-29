class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        int MAX_BITS = (max_num != 0) ? (log2(max_num) + 1) : 1;
        vector<vector<int>> next_index(n + 1, vector<int>(MAX_BITS, -1));
        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < MAX_BITS; ++bit) {
                next_index[i][bit] = next_index[i + 1][bit];
                if ((nums[i] >> bit) & 1) {
                    next_index[i][bit] = i;
                }
                // cout << next_index[i][bit] << ' ';
            }
            // cout << '\n';
        }
        vector<int> ret(n, -1);
        for (int i = 0; i < n; ++i) {
            int i2es = i;
            for (int bit = 0; bit < MAX_BITS; ++bit) {
                i2es = max(i2es, next_index[i][bit]);
            }
            ret[i] = i2es - i + 1;
        }
        return ret;
    }
};
