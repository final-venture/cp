#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int N;
vector<int> C;
vector<vector<pair<int, int>>> adj;
vector<int> dpIn, dpOut;
vector<int> subTreeCows;

void dfsIn(int node, int par) {
    dpIn[node] = 0;
    subTreeCows[node] = C[node];
    for (auto [neiDist, neiNode] : adj[node]) {
        if (neiNode == par) {
            continue;
        }
        dfsIn(neiNode, node);
        dpIn[node] += dpIn[neiNode] + subTreeCows[neiNode] * neiDist;
        subTreeCows[node] += subTreeCows[neiNode];
    }
}

void dfsOut(int node, int par) {
    for (auto [neiDist, neiNode] : adj[node]) {
        if (neiNode == par) {
            continue;
        }

        int totalInconvRootedAtNode = dpIn[node] + dpOut[node];
        int inconvFromNeiSubtree = dpIn[neiNode] + subTreeCows[neiNode] * neiDist;
        int inconvFromOthersToMe = totalInconvRootedAtNode - inconvFromNeiSubtree;
        int inconvFromMeToNei = inconvFromOthersToMe + (subTreeCows[1] - subTreeCows[neiNode]) * neiDist;
        dpOut[neiNode] = inconvFromMeToNei;
        dfsOut(neiNode, node);
    }
}

void solve()
{
    cin >> N;
    C.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i];
    }
    adj.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int A, B, L;
        cin >> A >> B >> L;
        adj[A].push_back({L, B});
        adj[B].push_back({L, A});
    }
    dpIn.resize(N + 1);
    dpOut.resize(N + 1);
    subTreeCows.resize(N + 1);

    dfsIn(1, -1);
    dpOut[1] = 0;
    dfsOut(1, -1);

    int ret = 1e18;
    for (int i = 1; i <= N; ++i) {
        ret = min(ret, dpIn[i] + dpOut[i]);
    }

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
