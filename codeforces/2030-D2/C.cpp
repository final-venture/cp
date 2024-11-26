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
    string b;
    cin >> b;
    if (b[0] == '1' || b[n - 1] == '1')
    {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 1; i < n; ++i)
    {
        if (b[i] == '0') continue;
        if (b[i] == b[i - 1])
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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
