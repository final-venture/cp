#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < N; ++i) {
        pq.push(s[i]);
    }

    int ret = 0;
    while (pq.size() > 1) {
        int x1 = pq.top();
        pq.pop();
        int x2 = pq.top();
        pq.pop();
        ret += x1 + x2;
        pq.push(x1 + x2);
    }
    cout << ret << '\n';
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
