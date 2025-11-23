class Solution
{
public:
    int maxBalancedSubarray(vector<int> &nums)
    {
        map<pair<int, int>, int> s2i{{{0, 0}, -1}};
        int n = nums.size();
        int ret = 0;
        int currVal = 0;
        int currParity = 0;
        for (int i = 0; i < n; ++i)
        {
            currVal ^= nums[i];
            if (nums[i] & 1)
            {
                --currParity;
            }
            else
            {
                ++currParity;
            }
            auto it = s2i.find({currVal, currParity});
            if (it != s2i.end())
            {
                // cout << currVal << ' ' << currParity << ' ' << it->second << ' ' << i << '\n';
                ret = max(ret, i - (it->second));
            }
            else
            {
                s2i[{currVal, currParity}] = i;
            }
        }
        return ret;
    }
};
