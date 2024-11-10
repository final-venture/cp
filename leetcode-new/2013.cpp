class DetectSquares
{
private:
    unordered_map<int, unordered_map<int, int>> mp;

public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        int x = point[0], y = point[1];
        ++mp[x][y];
    }

    int count(vector<int> point)
    {
        int count = 0;
        int x = point[0], y = point[1];
        for (auto &[cx, mpy] : mp)
        {
            int dx = cx - x;
            if (!dx)
                continue;
            for (auto &[cy, cnt] : mpy)
            {
                int dy = cy - y;
                if (abs(dx) != abs(dy))
                    continue;
                count += cnt * mp[cx][y] * mp[x][cy];
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
