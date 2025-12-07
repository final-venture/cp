class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                times[i] = {events[i][0], events[i][1]};
                continue;
            }
            times[i] = {events[i][0], events[i][1] - events[i - 1][1]};
        }
        // for (auto [x, y] : times)
        //     {
        //         cout << x << ' ' << y << '\n';
        //     }
        pair<int, int> ret = { -1, -1};
        for (int i = 0; i < n; ++i)
        {
            if (times[i].second > ret.second)
            {
                ret = times[i];
            }
            else if (times[i].second == ret.second && times[i].first < ret.first)
            {
                ret = times[i];
            }
        }
        return ret.first;
    }
};