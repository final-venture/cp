#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int n;
int r, a, b, c;
vector<vector<int>> adj;
vector<int> seen;

int gen() {
    r = (r * a + b) % c;
    return r;
}

int dfs(int node) {
    if (seen[node]) {
        return 0;
    }
    seen[node] = 1;

    int ret = 1;
    for (int nei : adj[node]) {
        ret += dfs(nei);
    }
    return ret;
}

void solve()
{
    cin >> r >> a >> b >> c;
    adj.clear();
    adj.resize(n + 1);
    seen.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x = gen() % n, y = gen()% n;
        while (x == y) {
            x = gen() % n;
            y = gen() % n;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    map<int, int, greater<>> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[dfs(i)]++;
    }
    int totalCount = 0;
    for (auto& [siz, count] : cnt) {
        if (siz == 0) {
            continue;
        }
        totalCount += count;
    }
    cout << totalCount << ' ';

    for (auto& [siz, count] : cnt) {
        if (siz == 0) {
            continue;
        }
        if (count == 1) {
            cout << siz << ' ';
        }
        else {
            cout << siz << "x" << count << ' ';
        }
    }   
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        solve();
    }
    return 0;
}
