#define ll long long
class Solution {
public:
    string getKey(int a, int b)
    {
        int g = gcd(a, b);
        return to_string(a / g) + "#" + to_string(b / g);
    }
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        ll ret = 0;
        unordered_map<string, ll> freqs;
        // rearrange: nums[p] / nums[q] = nums[s] / nums[r]
        // fix one variable.

        for (int r = 0; r < n; ++r)
        {
            int q = r - 2;
            for (int p = 0; p < q - 1; ++p)
            {
                ++freqs[getKey(nums[p], nums[q])];
            }
            for (int s = r + 2; s < n; ++s)
            {
                // cout << freqs[getKey(s, r)] << '\n';
                ret += freqs[getKey(nums[s], nums[r])];
            }
        }
        // for (auto& [s, f] : freqs)
        // {
        //     cout << s << ' ' << f << '\n';
        // }
        return ret;
    }
};
