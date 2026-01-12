class Solution
{
private:
    double targetArea;
    const double eps = 1e-5;

    bool check(double y, vector<vector<int>> &squares)
    {
        // cout << y << ' ';
        int n = squares.size();
        double currArea = 0;
        for (int i = 0; i < n; ++i)
        {

            double ly = squares[i][1], l = squares[i][2];
            if (ly >= y)
            {
                continue;
            }
            double uy = min(ly + l, y);
            currArea += (uy - ly) * l;
        }
        // cout << currArea << '\n';
        return (currArea < targetArea);
    }

public:
    double separateSquares(vector<vector<int>> &squares)
    {
        int n = squares.size();
        for (int i = 0; i < n; ++i)
        {
            targetArea += 1.0 * squares[i][2] * squares[i][2];
        }
        targetArea /= 2;

        double l = 0, r = 1e9 + 5;
        while (abs(r - l) > eps)
        {
            double m = l + (r - l) / 2;
            if (check(m, squares))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return l + (r - l) / 2;
    }
};
