#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int T, P;
    cin >> P >> T;
    vector<string> a(P + 1);
    vector<pair<int, int>> queries;
    int i;
    while (cin >> i) {
        int j;
        cin >> j;
        queries.push_back({j, i});
    }

    sort(queries.begin(), queries.end());
    for (auto [j, i] : queries) {
        a[i] += (to_string(j) + '#');
    }
    unordered_map<string, int> mp;
    for (int i = 1; i <= P; ++i) {
        // cerr << a[i] << '\n';
        mp[a[i]]++;
    }
    cout << (int)mp.size() << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
