class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        vector<int> sfx(n + 1, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            sfx[i] = sfx[i + 1] + (customers[i] == 'Y');
        }
        int penN = 0;
        int ret = -1;
        int best = 1e5 + 5;
        for (int i = 0; i <= n; ++i)
        {
            int cand = penN + sfx[i];
            if (cand < best)
            {
                best = cand;
                ret = i;
            }
            if (customers[i] == 'N')
            {
                ++penN;
            }
        }
        return ret;
    }
};
