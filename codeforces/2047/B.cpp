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
    string s;
    cin >> s;
    unordered_map<char, int> c2c;
    for (int i = 0; i < n; ++i)
    {
        ++c2c[s[i]];
    }
    char maxchar = '!';
    int maxcnt = 0;
    char minchar = '!';
    int mincnt = 15;
    for (auto& [x, y] : c2c)
    {
        if (y > maxcnt)
        {
            maxchar = x;
            maxcnt = y;
        }
    }
    c2c.erase(maxchar);
    for (auto& [x, y] : c2c)
    {
        if (y < mincnt)
        {
            minchar = x;
            mincnt = y;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (minchar != '!' && maxchar != '!' && s[i] == minchar)
        {
            s[i] = maxchar;
            break;
        }
    }
    cout << s << '\n';
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
