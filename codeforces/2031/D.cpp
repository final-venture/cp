#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

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
    int n;
    cin >> n;
    int trees[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> trees[i];
    }
    int pfx[n];
    pfx[0] = trees[0];
    for (int i = 1; i < n; ++i)
    {
        pfx[i] = max(pfx[i - 1], trees[i]);
    }
    int sfx[n];
    sfx[n - 1] = trees[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        sfx[i] = min(sfx[i + 1], trees[i]);
    }
    int res[n];
    res[n - 1] = pfx[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        if (sfx[i + 1] < pfx[i])
        {
            res[i] = res[i + 1];
        }
        else
        {
            res[i] = pfx[i];
        }
    }
    for (int x : res)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
