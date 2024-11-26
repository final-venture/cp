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
    ll b, c, d;
    cin >> b >> c >> d;
    unordered_map<string, bool> s2b {{"110", true}, {"101", true}, {"010", true}, {"001", true}, {"000", false}, {"111", false}, {"101", false}, {"010", false}};
    bitset<62> bb(b), cb(c), db(d), res(0);
    for (int i = 0; i < 62; ++i)
    {
        string cand = "";
        cand += to_string(bb[i]);
        cand += to_string(cb[i]);
        cand += to_string(db[i]);
        if (s2b.find(cand) == s2b.end())
        {
            cout << -1 << '\n';
            return;
        }
        if (s2b[cand])
        {
            res.flip(i);
        }
        else
        {
            res.reset(i);
        }
    }
    cout << res.to_ullong() << '\n';
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
