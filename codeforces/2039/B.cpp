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
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            cout << s.substr(i - 1, 2) << '\n';
            return;
        }
    }
    for (int i = 2; i < n; ++i)
    {
        if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i] != s[i - 2])
        {
            cout << s.substr(i - 2, 3) << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
