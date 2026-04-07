#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> nxt(n, n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] + 1 < a[i + 1]) {
            nxt[i] = i + 1;
        }
        else {
            nxt[i] = nxt[i + 1];
        }
    }
    vector<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] > a[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            nxt[i] = min(nxt[i], st.back());
        }
        st.push_back(i);
    }
    vector<int> dp(n + 1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = (n - i) + dp[nxt[i]];
    }
    // for (auto x : dp) {
    //     cout << x << ' ';
    // }
    cout << accumulate(dp.begin(), dp.end(), 0LL);
    cout << '\n';
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