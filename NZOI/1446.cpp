#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

#define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n, c, a;
    cin >> n >> c >> a;
    int cc = c; // init capital
    vector<int> prices(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
    }
    vector<int> maxx(n);
    int maxsf = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        maxsf = max(maxsf, prices[i]);
        maxx[i] = maxsf;
    }
    int i = 0;
    int s = 0; // 0 = need to buy, 1 = holding
    int ducks = 0;
    int bp = 0;
    while (i < n)
    {
        if (!s && prices[i] <= a && c >= prices[i] && maxx[i] > prices[i])
        {
            cout << "BUY " << c / prices[i] << '\n';
            ducks += c / prices[i];
            c %= prices[i];
            s = 1;
            bp = prices[i];
            ++i;
            continue;
        }
        if (s && prices[i] > bp)
        {
            cout << "SELL " << ducks << '\n';
            c += (prices[i] * ducks);
            ducks = 0;
            s = 0;
            ++i;
            continue;
        }
        if (s)
            cout << "HOLD" << '\n';
        else
            cout << "WAIT" << '\n';
        ++i;
    }
    cout << c - cc << '\n';
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
