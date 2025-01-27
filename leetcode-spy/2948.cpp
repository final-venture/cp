class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; ++i)
        {
            sorted[i] = {nums[i], i};
        }
        sort(sorted.begin(), sorted.end());

        vector<vector<int>> nnn;
        vector<vector<int>> iii;
        int i = 0;
        while (i < n)
        {
            vector<int> candn;
            vector<int> candi;
            while (i < n && (candn.empty() || sorted[i].first - limit <= candn.back()))
            {
                candn.push_back(sorted[i].first);
                candi.push_back(sorted[i].second);
                ++i;
            }
            nnn.push_back(candn);
            iii.push_back(candi);
        }

        for (auto &vec : iii)
        {
            sort(vec.begin(), vec.end());
        }

        vector<int> ret(n);
        for (int i = 0; i < nnn.size(); ++i)
        {
            for (int j = 0; j < nnn[i].size(); ++j)
            {
                ret[iii[i][j]] = nnn[i][j];
            }
        }
        return ret;
    }
};
