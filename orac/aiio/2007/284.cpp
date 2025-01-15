#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

vector<int> heads;
vector<int> tails;
int n, k;

bool check(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (heads[i] + tails[m] < x)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        // cout << x << ' ' << l << '\n';
        cnt += l;
    }
    // cout << cnt << '\n';
    return (cnt >= k);
}

void solve()
{
    cin >> n;
    cin >> k;
    heads.resize(n);
    tails.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heads[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tails[i];
    }
    int l = heads.back() + tails.back(), r = heads[0] + tails[0] + 1;
    if (l == r)
    {
        cout << l;
        return;
    }
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (check(m))
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    cout << l - 1;
}

signed main()
{
#ifndef LOCAL
    freopen("cats.in", "r", stdin);
    freopen("cats.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
