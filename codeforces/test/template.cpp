#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> acnt(n + 2, 0);
    vector<int> bcnt(n + 2, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        bcnt[i] = bcnt[i + 1] + (s[i] == '1');
        acnt[i] = acnt[i + 1] + (s[i] == '0');
    }
    // for (int x : acnt) cout << x << ' ';
    // cout << '\n';
    // for (int x : bcnt) cout << x << ' ';
    // cout << '\n';
    // for subarray [i, j], cnt is cnt[i] - cnt[j]
    int i = 0;
    int last = 0;
    int segs = 1;
    int score_a = 0;
    int score_b = 0;
    while (i < n)
    {
        if (s[i] == '1' && acnt[i] < bcnt[i])
            ++i;
        while (i < n && s[i] == '1' && acnt[i] >= bcnt[i])
        {
            ++i;
        }
        while (i < n && s[i] == '0')
        {
            ++i;
        }
        score_a += (acnt[last] - acnt[i]) * (segs - 1);
        score_b += (bcnt[last] - bcnt[i]) * (segs - 1);
        int total_b = score_b + (bcnt[i] - bcnt[n]) * segs;
        int total_a = score_a + (acnt[i] - acnt[n]) * segs;
        // cout << total_a << '\n';
        // cout << total_b << '\n';
        int diff = total_b - total_a;
        ++segs;
        if (diff >= k)
        {
            cout << segs << '\n';
            return;
        }
        last = i;
    }
    cout << -1 << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
