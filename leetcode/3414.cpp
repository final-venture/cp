#define ll long long
class Solution
{
public:
    vector<unordered_map<int, pair<ll, vector<int>>>> dp;
    vector<vector<int>> events;
    int n;
    pair<ll, vector<int>> dfs(int idx, int done)
    {
        if (idx >= n || done >= 4)
        {
            return {0, {}};
        }
        if (dp[idx].find(done) != dp[idx].end())
        {
            return dp[idx][done];
        }
        pair<ll, vector<int>> notTake = dfs(idx + 1, done);

        int l = idx + 1, r = n;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (events[m][0] > events[idx][1])
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        int nxt = l;

        pair<ll, vector<int>> take = dfs(nxt, done + 1);
        take.second.push_back(events[idx][3]);
        take.first += events[idx][2];

        sort(take.second.begin(), take.second.end());
        sort(notTake.second.begin(), notTake.second.end());

        pair<ll, vector<int>> ret;
        if (notTake.first > take.first)
        {
            ret = notTake;
        }
        else if (take.first > notTake.first)
        {
            ret = take;
        }
        else
        {
            ret.first = notTake.first;
            ret.second = min(take.second, notTake.second);
        }

        return dp[idx][done] = ret;
    }

    vector<int> maximumWeight(vector<vector<int>> &intervals)
    {
        n = intervals.size();
        events.resize(n);
        dp.resize(n);
        for (int i = 0; i < n; ++i)
        {
            events[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(events.begin(), events.end());
        pair<ll, vector<int>> ret = dfs(0, 0);
        return ret.second;
    }
};
