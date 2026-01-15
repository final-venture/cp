class Solution
{
public:
    long long maximumCoins(vector<vector<int>> &Coins, int k)
    {
        int n = Coins.size();
        vector<pair<pair<int, int>, int>> coins;
        for (auto &C : Coins)
        {
            int l = C[0], r = C[1], c = C[2];
            coins.push_back({{l, r}, c});
        }
        sort(coins.begin(), coins.end());
        vector<long long> pfx(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            pfx[i] = pfx[i - 1] + (coins[i - 1].first.second - coins[i - 1].first.first + 1) * 1LL * coins[i - 1].second;
        }
        long long ret = -1;
        for (int i = 0; i < n; ++i)
        {
            auto &[p, c] = coins[i];
            auto [l, r] = p;
            // check start
            int target = l + k - 1;
            if (target <= r)
            {
                ret = max(ret, 1LL * k * c);
            }
            else
            {
                auto it = upper_bound(coins.begin(), coins.end(), make_pair(make_pair(target, INT_MAX), 0));
                --it;
                int idx = it - coins.begin();
                long long stContrib = pfx[idx] - pfx[i];
                long long overlapEnd = min((long long)(it->first).second, (long long)target);
                long long edBagsTaken = max(0LL, overlapEnd - (it->first).first + 1);
                long long edContrib = edBagsTaken * (it->second);
                ret = max(ret, stContrib + edContrib);
            }
            // check end
            target = r - k + 1;
            if (target >= l)
            {
                ret = max(ret, 1LL * k * c);
            }
            else
            {
                auto it = upper_bound(coins.begin(), coins.end(), make_pair(make_pair(target, INT_MAX), -1));
                if (it != coins.begin())
                {
                    --it;
                    int idx = it - coins.begin();
                    long long edContrib = pfx[i + 1] - pfx[idx + 1];
                    long long stBagsTaken = 0;
                    if ((it->first).second >= target)
                    {
                        stBagsTaken = (it->first).second - target + 1;
                    }
                    long long stContrib = stBagsTaken * (it->second);
                    ret = max(ret, stContrib + edContrib);
                }
            }
        }
        return ret;
    }
};
