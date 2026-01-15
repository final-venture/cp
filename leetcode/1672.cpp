class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxx = 1;
        for (vector<int> &x : accounts)
        {
            int qty = accumulate(x.begin(), x.end(), 0);
            maxx = max(qty, maxx);
        }
        return maxx;
    }
};
