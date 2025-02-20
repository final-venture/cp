class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            int nn = nums[0].size();
            vector<int> a(n);
            for (int i = 0; i < n; ++i)
            {
                a[i] = stoi(nums[i], nullptr, 2);
            }
            string ret;
            for (int i = 0; i < (1 << nn); ++i)
            {
                int ok = 1;
                for (auto x : a)
                {
                    if (!(x ^ i))
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    ret = bitset<17>(i).to_string();
                    return ret.substr(17 - nn, nn);
                }
            }
            return ret.substr(17 - nn, nn);
        }
    };
    