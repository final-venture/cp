class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ret = 0;
        int n = points.size();
        for (int i = 1; i < n; ++i)
        {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            if (dx <= dy)
            {
                ret += dx;
                ret += (dy - dx);
            }
            else
            {
                ret += dy;
                ret += (dx - dy);
            }
        }
        return ret;
    }
};
