class Solution
{
private:
    int n;
    inline int getDistance(int i, int j)
    {
        if (i > j)
        {
            swap(i, j);
        }
        return min(abs(i - j), abs(i + n - j));
    }

public:
    long long minMoves(vector<int> &balance)
    {
        n = balance.size();
        long long acu = 0;
        int negIdx = -1, negBal = 1;

        for (int i = 0; i < n; ++i)
        {
            if (balance[i] < 0)
            {
                negIdx = i;
                negBal = balance[i];
            }
            acu += balance[i];
        }
        if (acu < 0)
        {
            return -1;
        }
        if (negIdx == -1)
        {
            return 0;
        }

        long long ret = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < n; ++i)
        {
            if (i == negIdx)
            {
                continue;
            }
            pq.push({getDistance(i, negIdx), balance[i]});
        }
        while (!pq.empty() && negBal <= 0)
        {
            auto [dist, bal] = pq.top();
            pq.pop();
            int toBal = min(bal, -negBal);
            ret += (1LL * dist * toBal);
            negBal += toBal;
        }

        return ret;
    }
};
