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
    int n, k;
    cin >> n >> k;
    if (k == 1 && n == 1) 
    {
        cout << 1 << '\n' << 1 << '\n';
        return;
    }
    if (k == 1 || k >= n)
    {
        cout << -1 << '\n';
        return;
    }
    cout << 3 << '\n';
    if (k % 2)
    {
        cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
    }
    else 
    {
        cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
    }
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
