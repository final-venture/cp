#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> st;
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        while (!st.empty() && st.back().first <= a[i]) {
            auto [ht, minHt] = st.back(); 
            ret = max(ret, ht - minHt);
            st.pop_back();
            if (!st.empty()) {
                st.back().second = min(minHt, st.back().second);
            }
        }
        st.push_back({a[i], a[i]});
    }

    st.clear();
    reverse(a.begin(), a.end());
    
    for (int i = 0; i < N; ++i) {
        while (!st.empty() && st.back().first <= a[i]) {
            auto [ht, minHt] = st.back(); 
            ret = max(ret, ht - minHt);
            st.pop_back();
            if (!st.empty()) {
                st.back().second = min(minHt, st.back().second);
            }
        }
        st.push_back({a[i], a[i]});
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
