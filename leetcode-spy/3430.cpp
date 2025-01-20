#define ll long long
class Solution
{
private:
    vector<pair<int, int>> sorted;
    int n;
    int k;
    struct UF
    {
    private:
        vector<int> par;
        vector<int> rank;
        vector<pair<int, int>> interval;

    public:
        UF(int n)
        {
            par.resize(n);
            rank.resize(n);
            interval.resize(n);
            for (int i = 0; i < n; ++i)
            {
                par[i] = i;
                interval[i] = {i, i};
            }
        }
        int find(int x)
        {
            if (x != par[x])
            {
                par[x] = find(par[x]);
            }
            return par[x];
        }
        void unionn(int x1, int x2)
        {
            int p1 = find(x1), p2 = find(x2);
            if (rank[p1] > rank[p2])
            {
                par[p2] = par[p1];
                interval[p1].first = min(interval[p1].first, interval[p2].first);
                interval[p1].second = max(interval[p1].second, interval[p2].second);
            }
            else if (rank[p2] > rank[p1])
            {
                par[p1] = par[p2];
                interval[p2].first = min(interval[p1].first, interval[p2].first);
                interval[p2].second = max(interval[p1].second, interval[p2].second);
            }
            else
            {
                par[p1] = par[p2];
                ++rank[p2];
                interval[p2].first = min(interval[p1].first, interval[p2].first);
                interval[p2].second = max(interval[p1].second, interval[p2].second);
            }
        }
        pair<int, int> getIVL(int x)
        {
            return interval[find(x)];
        }
    };

public:
    ll minOrMaxSum()
    {
        UF uf(n);
        vector<int> ok(n, 0);
        ll ret = 0;
        for (int i = 0; i < n; ++i)
        {
            auto &[num, idx] = sorted[i];
            ok[idx] = 1;
            if (idx - 1 >= 0 && ok[idx - 1])
            {
                uf.unionn(idx, idx - 1);
            }
            if (idx + 1 < n && ok[idx + 1])
            {
                uf.unionn(idx, idx + 1);
            }
            auto [l, r] = uf.getIVL(idx);
            int dist_r = r - idx;
            int dist_l = idx - l;
            ll x = min(k, dist_r + dist_l + 1);
            ll cand = x * (x + 1) / 2;
            if (x - 1 - dist_r > 0)
                cand -= (x - 1 - dist_r) * (x - dist_r) / 2;
            if (x - 1 - dist_l > 0)
                cand -= (x - 1 - dist_l) * (x - dist_l) / 2;
            ret += cand * num;
        }
        return ret;
    }

    long long minMaxSubarraySum(vector<int> &nums, int k)
    {
        n = nums.size();
        this->k = k;
        sorted.resize(n);
        ll ret = 0;
        for (int i = 0; i < n; ++i)
        {
            sorted[i] = {nums[i], i};
        }
        sort(sorted.begin(), sorted.end());
        ret += minOrMaxSum();
        cout << minOrMaxSum() << '\n';
        sort(sorted.begin(), sorted.end(), greater<>());
        ret += minOrMaxSum();
        cout << minOrMaxSum() << '\n';
        return ret;
    }
};
