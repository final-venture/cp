#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> st;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.insert(x);
    }

    int ret = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int val = *st.lower_bound(x);
        ret += val - x;
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
