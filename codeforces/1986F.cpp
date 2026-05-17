#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<vector<int>> adj;
int n, m;
vector<int> time_in;
vector<int> min_time;
vector<int> subtree_size;
int timer;
int ret;

void tarjan(int node, int par) {
    time_in[node] = ++timer;
    min_time[node] = timer;
    
    for (int nei : adj[node]) {
        if (nei == par) {
            continue;
        }
        if (!time_in[nei]) {
            // if not visited (this is a tree edge), run the algo and find the
            // min_time for that node
            tarjan(nei, node);
            subtree_size[node] += subtree_size[nei];
            // PROPAGATE the min time that the child can reach back to the parent
            // (since we can go parent->child->min node VIA the back edge)
            min_time[node] = min(min_time[node], min_time[nei]);

            // LABEL: (1)
            if (min_time[nei] > time_in[node]) {
                int a = subtree_size[nei];
                int b = n - a;
                int cand = a * (a-1) / 2 + b * (b-1) / 2;
                ret = min(cand, ret);
            }
        }
        else {
            // if already visited: this is a back edge
            // take into account this NEW back edge into our min time of current node
            // This is the only instance that min_time is updated (and not propagated).
            min_time[node] = min(min_time[node], time_in[nei]);
        }
    }

    // PUTTING LOOP LABELLED (1) HERE IS FINE TOO.
    // for (int nei : adj[node]) {
    //     if (nei == par) {
    //         continue;
    //     }
    //     if (min_time[nei] > time_in[node]) {
    //         int a = subtree_size[nei];
    //         int b = n - a;
    //         int cand = a * (a-1) / 2 + b * (b-1) / 2;
    //         ret = min(cand, ret);
    //     }
    // }
}

void solve()
{
    // For an scc with size n, each ordered pair of vertices can reach each other, so there are
    // n*(n-1)/2 pairs.
    // if we split this up into 2 scc with size a and size b:
    // a + b = n.
    // Find all bridges, and the values of a and b for each split using Tarjan's, then return
    // the one that gives the minimum of C(a, 2) + C(b, 2);
    cin >> n >> m;
    timer = 0;
    ret = n * (n-1) / 2;
    adj.clear();
    adj.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 0 is a sentinel value to denote unseen
    time_in.assign(n, 0);

    min_time.assign(n, 1e18);
    subtree_size.assign(n, 1);

    tarjan(0, -1);

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
