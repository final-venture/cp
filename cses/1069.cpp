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
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    int maxx = 1;
    while (r < n)
    {
        if (s[l] != s[r])
        {
            l = r;
        }
        maxx = max(maxx, r - l + 1);
        ++r;
    }
    cout << maxx << '\n';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
