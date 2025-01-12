#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int LOG = 22;
vector<pair<int, int>> adj[100005];
vector<vector<int>> up(LOG, vector<int>(100005, -1));
vector<ll> dists(100005, 0);
int depth[100005];

// dists[i][j] is distance from node j to 2^i-th parent.

void dfs(int node, int d, int p)
{
	// cout << node << ' ' << d << ' ' << p << endl;
	depth[node] = d;
	for (auto [neiDist, neiNode] : adj[node])
	{
		if (neiNode == p) continue;
		up[0][neiNode] = node;
		dists[neiNode] = neiDist + dists[node];
		dfs(neiNode, d + 1, node);
	}
}

void solve()
{
	memset(depth, -1, sizeof(depth));
	int n, q;
	cin >> n >> q;
	int a, b, c;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	int root = b;
	dfs(root, 0, -1);
	for (int i = 1; i < LOG; ++i)
	{
		for (int j = 0; j < 100005; ++j)
		{
			int p = up[i - 1][j];
			if (p == -1) continue;
			up[i][j] = up[i - 1][p];
		}
	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout << depth[i] << '\n';
	// }

	// for (int i = 0; i < LOG; ++i)
	// {
	// 	for (int j = 0; j <= n; ++j)
	// 	{
	// 		cout << up[i][j].first << ' ';
	// 	}
	// 	cout << '\n';
	// }

	while (q--) {
		int qa, qb;
		cin >> qa >> qb;

		if (depth[qa] > depth[qb]) swap(qa, qb);
		int diff = depth[qb] - depth[qa];
		ll dist = dists[qa] + dists[qb];
		// cout << dist << '\n';

		for (int i = LOG - 1; i >= 0; --i) {
			if ((1 << i) & diff)
			{
				qb = up[i][qb];
			}
		}

		if (qa == qb) {
			cout << dist - dists[qa] * 2ll << '\n';
			continue;
		}

		for (int i = LOG - 1; i >= 0; --i) {
			if (up[i][qa] != up[i][qb]) {
				qa = up[i][qa];
				qb = up[i][qb];
			}
		}

		cout << dist - dists[up[0][qa]] * 2ll << '\n';
	}
}

signed main()
{
	cin.tie(0);
	iostream::sync_with_stdio(false);
	solve();
	return 0;
}
