#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
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

int solve()
{
    int r, c;
    cin >> r >> c;
    --r; --c;
    if (r >= c)
    {
        int s;
        if (r & 1)
        {
            s = (1 + r) * (1 + r);
        }
        else
        {
            s = 1 + (r * r);
        }
        return (r & 1 ? s - c : s + c);
    }
    else
    {
        int s;
        if (c & 1)
        {
            s = 1 + (c * c);
        }
        else
        {
            s = (1 + c) * (1 + c);
        }
        return (c & 1 ? s + r : s - r);
    }
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
