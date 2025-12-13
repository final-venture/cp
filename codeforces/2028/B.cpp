#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if (b == 0)
    {
        if (c >= n)
            cout << n << '\n';
        else if (n > c + 2)
            cout << -1 << '\n';
        else
            cout << n - 1 << '\n';
        return;
    }
    ll x = n - max(0ll, (n - c + b - 1) / b);
    cout << x << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
