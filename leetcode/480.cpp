class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        set<pair<int, int>, greater<>> small;
        set<pair<int, int>> large;
        vector<double> ret;

        for (int i = 0; i < k - 1; ++i)
        {
            large.insert({nums[i], i});
        }
        for (int i = k - 1; i < n; ++i)
        {
            large.insert({nums[i], i});
            if (!small.empty() && *large.begin() < *small.begin())
            {
                auto it = small.begin();
                large.insert(*it);
                small.erase(it);
            }
            while (large.size() > small.size())
            {
                auto it = large.begin();
                small.insert(*it);
                large.erase(it);
            }
            double med = small.begin()->first;
            if (small.size() == large.size())
            {
                med += large.begin()->first;
                med /= 2;
            }
            ret.push_back(med);
            auto to_remove_small = small.find({nums[i - k + 1], i - k + 1});
            auto to_remove_large = large.find({nums[i - k + 1], i - k + 1});
            if (to_remove_small != small.end())
            {
                small.erase(to_remove_small);
            }
            else if (to_remove_large != large.end())
            {
                large.erase(to_remove_large);
            }
        }

        return ret;
    }
};
