class Solution
{
public:
    int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff)
    {
        // vector<int> pfx(n + 1, 0);
        // for (int i = 1; i < n; ++i) {
        //     pfx[i] = pfx[i - 1] + diff[i];
        // }
        vector<int> restriction(n, 1e9);
        restriction[0] = 0;
        for (auto &r : restrictions)
        {
            int idx = r[0], maxVal = r[1];
            restriction[idx] = maxVal;
        }
        for (int i = 1; i < n; ++i)
        {
            restriction[i] = min(restriction[i - 1] + diff[i - 1], restriction[i]);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            restriction[i] = min(restriction[i + 1] + diff[i], restriction[i]);
        }
        // for (auto x : restriction) {
        //     cout << x << ' ';
        // }
        return *max_element(restriction.begin(), restriction.end());
    }
};
