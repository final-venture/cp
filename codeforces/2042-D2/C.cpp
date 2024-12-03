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
    vector<int> sfx(n + 1, 0);
    for (int i = n - 1; i >= 1; --i)
    {
        sfx[i] = sfx[i + 1] + (s[i] == '1' ? 1 : -1);
    }
    int curr = 0;
    sort(all(sfx), greater<void>());
    for (int i = 0; i < n; ++i)
    {
        curr += sfx[i];
        if (curr >= k)
        {
            cout << i + 2 << '\n';
            return;
        }
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
