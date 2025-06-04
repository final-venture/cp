class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i)
        {
            arr[i] = {capital[i], profits[i]};
        }
        int i = 0;
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        while (k--)
        {
            while (i < n && arr[i].first <= w)
            {
                pq.push(arr[i].second);
                ++i;
            }
            if (pq.empty())
                break;
            int profit = pq.top();
            w += profit;
            pq.pop();
        }
        return w;
    }
};
