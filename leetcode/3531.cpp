class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        unordered_map<int, pair<int, int>> y2x, x2y;
        for (auto &b : buildings)
        {
            int x = b[0], y = b[1];
            if (y2x.find(y) == y2x.end())
            {
                y2x[y] = {x, x};
            }
            else
            {
                y2x[y] = {min(y2x[y].first, x), max(y2x[y].second, x)};
            }
            if (x2y.find(x) == x2y.end())
            {
                x2y[x] = {y, y};
            }
            else
            {
                x2y[x] = {min(x2y[x].first, y), max(x2y[x].second, y)};
            }
        }
        int ret = buildings.size();
        for (auto &b : buildings)
        {
            int x = b[0], y = b[1];
            if (y2x[y].first >= x || y2x[y].second <= x || x2y[x].first >= y || x2y[x].second <= y)
            {
                --ret;
            }
        }
        return ret;
    }
};
