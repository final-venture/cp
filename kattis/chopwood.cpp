#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 3, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    if (a[n - 1] != n + 1) {
        cout << "Error" << '\n';
        return;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= n + 1; ++i) {
        if (!cnt[i]) {
            pq.push(i);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int leaf = pq.top();
        pq.pop();
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) {
            pq.push(a[i]);
        }
        cout << leaf << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
