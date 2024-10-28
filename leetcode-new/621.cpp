class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> taskcount(26, 0);
        for (char task : tasks)
            ++taskcount[task - 'A'];
        priority_queue<int> pq;
        for (int c : taskcount)
        {
            if (c > 0)
                pq.push(c);
        }
        queue<pair<int, int>> q;

        int time = 0;
        while (!pq.empty() || !q.empty())
        {
            ++time;
            if (!pq.empty())
            {
                int x = pq.top();
                if (x > 1)
                {
                    q.push({time + n, x - 1});
                }
                pq.pop();
            }
            if (!q.empty())
            {
                auto &x = q.front();
                if (x.first == time)
                {
                    pq.push(x.second);
                    q.pop();
                }
            }
        }
        return time;
    }
};
