#define ll long long
class Solution {
private:
    vector<ll> dpin;
    vector<ll> dpout;
    vector<int> price;
    vector<vector<int>> adj;
public:
    ll dfsIn(int node, int par)
    {
        ll add = 0;
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            add = max(add, dfsIn(nei, node));
        }
        return dpin[node] = (price[node] + add);
    }
    void dfsOut(int node, int par)
    {
        ll maxx1 = 0, maxx2 = 0;
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            if (dpin[nei] > maxx1)
            {
                maxx2 = maxx1;
                maxx1 = dpin[nei];
            }
            else if (dpin[nei] > maxx2)
            {
                maxx2 = dpin[nei];
            }
        }
        for (int nei : adj[node])
        {
            if (nei == par) continue;
            ll maxx = (dpin[nei] == maxx1) ? maxx2 : maxx1;
            dpout[nei] = max(dpout[node] + price[node], maxx + price[node]);
            dfsOut(nei, node);
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.resize(n);
        this -> price = price;
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        dpin.resize(n);
        dpout.resize(n);
        dpout[0] = 0; // dpout[0] != prices[0] because we will be double counting,
        // since dpin takes into the node itself, dpout can't do this.
        dfsIn(0, -1);
        dfsOut(0, -1);

        // for (auto x : dpout) cout << x << ' ';
        // cout << '\n';
        // for (auto x : dpin) cout << x << ' ';

        ll ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ret = max(ret, max(dpout[i], dpin[i] - price[i]));
        }
        return ret;
    }
};
