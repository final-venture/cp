class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> nc;

        for (int num : nums)
        {
            nc[num] += 1;
        }

        vector<vector<int>> v(nums.size() + 1);
        for (pair<const int, int> &x : nc)
        {
            v[x.second].push_back(x.first);
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            while (!v[i].empty() && res.size() < k)
            {
                res.push_back(v[i].back());
                v[i].pop_back();
            }
        }
        return res;
    }
};
