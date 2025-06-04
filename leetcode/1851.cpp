class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        unordered_map<int, int> q2r;
        vector<int> s_queries(queries);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mh;

        sort(s_queries.begin(), s_queries.end());
        sort(intervals.begin(), intervals.end());

        int i = 0;
        for (int q : s_queries)
        {
            while (i < intervals.size() && intervals[i][0] <= q)
            {
                int start = intervals[i][0];
                int end = intervals[i][1];
                mh.push({end - start + 1, end});
                ++i;
            }

            while (!mh.empty() && mh.top().second < q)
            {
                mh.pop();
            }
            if (mh.empty())
            {
                q2r[q] = -1;
            }
            else
            {
                q2r[q] = mh.top().first;
            }
        }
        vector<int> res;
        for (int q : queries)
        {
            res.push_back(q2r[q]);
        }
        return res;
    }
};
