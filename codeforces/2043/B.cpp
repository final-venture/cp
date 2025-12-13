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
    int n, d;
    cin >> n >> d;
    set<int> ret;
    ret.insert(1);
    if (d & 1) ret.insert(d);
    if (d == 9 || d == 6) ret.insert(3);
    if (n >= 3)
    {
        ret.insert(3);
        ret.insert(7);
        // if (d == 4 || d == 2 || d == 8)
        //     ret.insert(6);
        if (d == 3 || d == 6)
            ret.insert(9);
    }
    // if (d % 2 == 0) ret.insert(2);
    // if (d == 8) ret.insert(4);
    if (n >= 6) ret.insert(9);
    for (int x : ret) cout << x << ' ';
    cout << '\n';
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
