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
    int sticks[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> sticks[i];
    }
    int cs = sticks[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        if (sticks[i] < cs)
        {
            cs = sticks[i];
            continue;
        }
        if (sticks[i] - 1 > cs)
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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
