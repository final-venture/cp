class Solution
{
public:
    int minSwaps(vector<int> &nums, vector<int> &forbidden)
    {
        // if nums[i] != nums[j]:
        // both are forbidden: can swap
        // one is forbidden and one is not: can swap only if forbidden[i] != forbidden[j]
        // and both aren't forbidden, never need to swap

        int n = nums.size();
        unordered_map<int, int> n2c;
        for (int i = 0; i < n; ++i)
        {
            n2c[nums[i]]++;
        }
        unordered_map<int, int> f2c;
        for (int i = 0; i < n; ++i)
        {
            f2c[forbidden[i]]++;
        }
        for (auto &[num, c] : f2c)
        {
            if (n - c < n2c[num])
            {
                return -1;
            }
        }

        unordered_map<int, int> n2conf;
        int total_conf = 0, max_conf = 0;

        for (int i = 0; i < n; ++i)
        {
            if (forbidden[i] == nums[i])
            {
                n2conf[nums[i]]++;
                max_conf = max(max_conf, n2conf[nums[i]]);
                total_conf++;
            }
        }

        return max(max_conf, (total_conf + 1) / 2);
    }
};
