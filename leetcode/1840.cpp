class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int sz = restrictions.size();
        if (restrictions[sz - 1][0] != n)
        {
            restrictions.push_back({n, n + 5});
        }
        sz = restrictions.size();

        int maxx = 0;
        for (int i = 1; i < sz; ++i)
        {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }
        for (int i = sz - 2; i >= 0; --i)
        {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }
        for (int i = 1; i < sz; ++i)
        {
            maxx = max(maxx, (restrictions[i][1] + restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0])) / 2);
        }
        return maxx;
    }
};
