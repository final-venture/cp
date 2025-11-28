#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> cake(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cake[i];
    }
    vector<ll> sums(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
    {
        sums[i] = sums[i - 1] + cake[i - 1];
    }
    vector<int> pfx{0};
    int currSum = 0;
    for (int i = 0; i < n; ++i)
    {
        currSum += cake[i];
        if (currSum >= v)
        {
            pfx.push_back(i + 1);
            currSum = 0;
        }
    }
    vector<int> sfx{n};
    currSum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        currSum += cake[i];
        if (currSum >= v)
        {
            sfx.push_back(i);
            currSum = 0;
        }
    }

    // for (ll x : sums)
    //     cout << x << ' ';
    // cout << '\n';
    // for (int x : pfx)
    //     cout << x << ' ';
    // cout << '\n';
    // for (int x : sfx)
    //     cout << x << ' ';
    // cout << endl;

    ll res = -1;
    for (int i = 0; i <= m; ++i)
    {
        int j = m - i;
        if (i >= pfx.size() || j >= sfx.size() || pfx[i] > sfx[j])
            continue;
        res = max(res, sums[sfx[j]] - sums[pfx[i]]);
    }
    cout << res << '\n';
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
