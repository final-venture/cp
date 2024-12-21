#define ll long long
class Solution {
private:
    vector<ll> seg;
    vector<vector<int>> adj;
    vector<int> tour_in;
    vector<int> tour_out;
    vector<int> tour_vals;
    vector<int> values;
    int timer = 0;
public:
    void tour(int node, int par)
    {
        tour_in[node] = timer;
        tour_vals[tour_in[node]] = values[node];
        ++timer;
        for (int nei : adj[node])
        {
            if (nei != par)
            {
                tour(nei, node);
            }
        }
        tour_out[node] = timer;
    }

    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = tour_vals[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(idx * 2 + 1, l, mid);
        build(idx * 2 + 2, mid + 1, r);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    ll query(int idx, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        int mid = l + (r - l) / 2;
        ll left = query(idx * 2 + 1, l, mid, ql, qr);
        ll right = query(idx * 2 + 2, mid + 1, r, ql, qr);
        return left + right;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n); seg.resize(4 * n); tour_in.resize(n); tour_out.resize(n);
        this -> values = values;
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        tour_vals.resize(n);
        tour(0, -1);
        build(0, 0, n - 1);
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            ll summ = query(0, 0, n - 1, tour_in[i], tour_out[i] - 1);
            if (summ % k == 0) ++ret;
        }
        return ret;
    }
};
