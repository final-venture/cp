#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

vector<int> st;

void solve()
{
    st.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        
        if (!st.empty() && st.back() > x) {
            int curr = st.back();
            st.pop_back();
            st.push_back(curr + x);
        } 
        else {
            st.push_back(x);
        }
    }

    int ret = st.back();
    cout << ret << "\n";
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
