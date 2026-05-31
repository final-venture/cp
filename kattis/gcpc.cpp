#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define EPS 1e-9

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int n, m;
    cin >> n >> m;
    ordered_set<pair<int, pair<int, int>>> os;
    vector<int> solved(n + 1, 0);
    vector<int> penalty(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int t, p;
        cin >> t >> p;
        auto it = os.find({-solved[t], {penalty[t], t}});
        if (it != os.end()) {
            os.erase(it);
        }
        solved[t]++;
        penalty[t] += p;
        os.insert({-solved[t], {penalty[t], t}});
        int better = os.order_of_key({-solved[1], {penalty[1], 1}});

        cout << better + 1 << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
