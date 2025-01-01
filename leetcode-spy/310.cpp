// IN OUT DP
class Solution {
private:
	vector<vector<int>> adj;
	vector<int> dpin;
	vector<int> dpout;
public:
	void dfsIn(int node, int par)
	{
		for (int nei : adj[node])
		{
			if (nei == par) continue;
			dfsIn(nei, node);
			dpin[node] = max(dpin[node], dpin[nei] + 1);
		}
	}

	void dfsOut(int node, int par)
	{
		int maxx1 = INT_MIN, maxx2 = INT_MIN;
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
			int maxx = (maxx1 == dpin[nei]) ? maxx2 : maxx1;
			// maxx + 2 because we need to go up from nei to node, then node to other nei.
			dpout[nei] = max(dpout[node] + 1, maxx + 2);
			dfsOut(nei, node);
		}
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		adj.resize(n);
		dpin.resize(n, 0); dpout.resize(n);
		dpout[0] = 0;
		for (auto& edge : edges)
		{
			int u = edge[0], v = edge[1];
			adj[u].push_back(v); adj[v].push_back(u);
		}
		dfsIn(0, -1);
		dfsOut(0, -1);

		int curr = INT_MAX;
		vector<int> ret;

		// for (int x : dpout) cout << x << ' ';
		// cout << '\n';
		// for (int x : dpin) cout << x << ' ';

		for (int i = 0; i < n; ++i)
		{
			int cand = max(dpin[i], dpout[i]);
			if (cand < curr)
			{
				curr = cand;
				ret.clear();
			}
			if (cand <= curr)
				ret.push_back(i);
		}
		return ret;
	}
};

// Tree Pruning - Bottom-Up
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj(n);
		vector<int> deg(n);
		for (auto& edge : edges)
		{
			int u = edge[0], v = edge[1];
			adj[u].push_back(v); adj[v].push_back(u);
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
		{
			deg[i] = adj[i].size();
			if (deg[i] == 1) q.push({i, 0});
		}

		int curr_layer = -1;
		vector<int> st {0};
		while (!q.empty())
		{
			auto [node, layer] = q.front();
			q.pop();
			if (layer > curr_layer)
			{
				st.clear();
				++curr_layer;
			}
			st.push_back(node);
			for (int nei : adj[node])
			{
				--deg[nei];
				if (deg[nei] == 1) q.push({nei, layer + 1});
			}
		}
		return st;
	}
};
