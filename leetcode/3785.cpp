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

        int ret = 0;
        set<pair<int, int>> conflicts;
        unordered_map<int, int> n2conf;

        for (int i = 0; i < n; ++i)
        {
            if (forbidden[i] == nums[i])
            {
                n2conf[nums[i]]++;
            }
        }

        for (auto &[num, conf] : n2conf)
        {
            conflicts.insert({conf, num});
        }

        while (!conflicts.empty())
        {
            auto smallIt = conflicts.begin();
            auto [smallCnt, smallNum] = *smallIt;
            if (conflicts.size() == 1)
            {
                ret += smallIt->first;
                conflicts.erase(smallIt);
                break;
            }
            auto largeIt = conflicts.rbegin();
            auto [largeCnt, largeNum] = *largeIt;
            int toResolve = min(smallIt->first, largeIt->first);
            ret += toResolve;
            conflicts.erase(smallIt);
            conflicts.erase(prev(conflicts.end()));
            if (largeCnt > toResolve)
            {
                conflicts.insert({largeCnt - toResolve, largeNum});
            }
        }

        return ret;
    }
};
