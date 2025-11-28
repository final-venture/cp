#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
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
    int l, r, g;
    cin >> l >> r >> g;
    l = (l + g - 1) / g;
    r = r / g;
    if (l > r)
    {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    int L = -1, R = -1;
    int ok = 0;
    int res = 2e18;
    const int lim = 30;
    // https://www.cnblogs.com/lingfunny/p/18629029
    // https://www.bilibili.com/video/BV1arkoY8EY8/?spm_id_from=333.337.search-card.all.click
    // We can early terminate in the loops for better runtime, and actually get rid of the limit entirely.
    // Prime density allows us to find a solution in few iterations - no one knows the proof, so we just memorise ok?
    for (int i = l; i <= min(r, l + lim); ++i)
    {
        if (i - l >= res) break;
        // we can break here if i - l >= res - i.e. we can't find a better solution than current optimal.
        for (int j = r; j >= max(l, r - lim); --j)
        {
            if (gcd(i, j) == 1 && i - l + r - j < res)
            {
                res = i - l + r - j;
                L = i; R = j;
                break;
            }
        }
    }
    if (L == -1)
    {
        cout << -1 << ' ' << -1 << '\n';
    }
    else
    {
        cout << L * g << ' ' << R * g << '\n';
    }
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
