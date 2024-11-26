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
    int zeroes = 0;
    int ones = 0;
    int minn = 0;
    int maxx = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        int x;
        cin >> x;
        if (!x) ++zeroes;
        else ++ones;
    }
    int z = zeroes % 2;
    int o = ones % 2;
    if (z || o) minn = 1;
    maxx += min(zeroes, ones);
    cout << minn << ' ' << maxx << '\n';
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
