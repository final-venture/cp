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
    // iterate from right to left
    // and add to a monotonically decreasing stack
    stack<int> st;
    // stack = [2]
    // 3
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[i] > st.top()) {
            st.pop();
        }
        st.push(a[i]);
    }

    // while(!st.empty()) {
    //     cout << st.top() << ' ';
    //     st.pop();
    // }
    // cout << '\n';

    cout << st.size() << '\n';
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
