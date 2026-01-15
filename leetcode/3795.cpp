class Solution
{
public:
    int minLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int accu = 0;
        int ret = 1e6;
        unordered_map<int, int> n2c;
        while (r < n)
        {
            while (accu < k && r < n)
            {
                if (!n2c[nums[r]])
                {
                    accu += nums[r];
                }
                n2c[nums[r]]++;
                ++r;
            }
            while (accu >= k)
            {
                n2c[nums[l]]--;
                if (!n2c[nums[l]])
                {
                    accu -= nums[l];
                }
                ++l;
            }
            ret = min(ret, r - l + 1);
        }
        return ret > n ? -1 : ret;
    }
};
