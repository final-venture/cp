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

class Storage
{
public:
    set<pair<int, pair<int, int>>> emp; // empty intervals that are not terminal: {size, l, r}
    set<pair<int, int>> fi {{0, 0}}; // file intervals
    map<int, pair<int, int>> f2i {{0, {0, 0}}}; // file to interval
    int id = 1;
    int create(int sz)
    {
        if (fi.empty())
        {
            int nr = 1 + (sz / 1474560);
            fi.insert({1, nr});
            f2i[id] = {1, nr};
            ++id;
            return 1;
        }
        auto it = emp.lower_bound(sz);
        if (it != emp.end())
        {
            int fl = (*it).second.first;
            int fr = (*it).second.second;
            int nl = fl;
            int nr = nl + (sz / 1474560);
        }
        else
        {

        }
        int nl = (*fi.rbegin()).second + 1;
        int nr = nl + (sz / 1474560);
    }
};
// C y: create a new file with y bytes

// D x: destroy file x

// M x y: modify file x, after which it will be y bytes

// O: optimise the disk layout

int n, m;

void solve()
{
    cin >> n >> m;
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
