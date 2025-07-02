class Solution
{
public:
    class UF
    {
    private:
        vector<int> par, rank;

    public:
        UF(int n)
        {
            par.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; ++i)
                par[i] = i;
        }

        int find(int x)
        {
            if (x != par[x])
                par[x] = find(par[x]);
            return par[x];
        }

        void unionn(int x1, int x2)
        {
            int p1 = find(x1), p2 = find(x2);
            if (p1 == p2)
                return;

            if (rank[p1] > rank[p2])
            {
                par[p2] = p1;
            }
            else if (rank[p1] < rank[p2])
            {
                par[p1] = p2;
            }
            else
            {
                par[p1] = p2;
                ++rank[p2];
            }
        }
    };

    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        int nn = edges.size();
        vector<pair<int, pair<long long, pair<int, int>>>> edges2(nn);

        for (int i = 0; i < nn; ++i)
        {
            edges2[i] = {edges[i][3], {edges[i][2], {edges[i][0], edges[i][1]}}};
        }

        sort(edges2.begin(), edges2.end(), greater<>());

        UF uf(n);
        long long stab = 1e6;
        multiset<pair<int, long long>> to_upgrade;
        int cnt = 0;

        for (int i = 0; i < nn; ++i)
        {
            long long u = edges2[i].second.second.first;
            long long v = edges2[i].second.second.second;
            long long wt = edges2[i].second.first;
            long long req = edges2[i].first;

            if (req && uf.find(u) == uf.find(v))
            {
                return -1;
            }

            if (uf.find(u) != uf.find(v))
            {
                uf.unionn(u, v);
                ++cnt;

                if (req)
                {
                    stab = min(stab, wt);
                }
                else
                {
                    to_upgrade.insert({0, wt});
                }
            }
        }

        if (cnt != n - 1)
        {
            return -1;
        }

        for (int i = 0; i < k; ++i)
        {
            if (to_upgrade.empty())
            {
                break;
            }
            auto it = to_upgrade.begin();
            auto [done, old_wt] = (*it);
            if (done)
                break;
            to_upgrade.erase(it);
            long long new_wt = old_wt * 2;
            to_upgrade.insert({1, new_wt});
        }

        for (auto [done, x] : to_upgrade)
        {
            stab = min(stab, x);
        }

        return stab;
    }
};
