#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    multiset<pair<int, int>> st;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'a') {
            int E, G;
            cin >> E >> G;
            st.insert({E, G});
        }
        else if (s[0] == 'q') {
            int X;
            cin >> X;
            int ret = 0;
            while (X > 0) {
                // find E <= X, and the one with largest gold reward.
                // can do this with upper bound on X, then --it.
                auto it = st.lower_bound({X, 1e7});
                if (it == st.begin()) {
                    break;
                }
                --it;
                auto [E, G] = *it;
                st.erase(it);
                X -= E;
                ret += G;
            }
            cout << ret << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
