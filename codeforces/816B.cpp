#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()

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
    int n, k, q;
    cin >> n >> k >> q;
    int cnts[200002];
    int pfx[200002];
    memset(cnts, 0, sizeof(cnts));
    memset(pfx, 0, sizeof(cnts));
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        ++cnts[l];
        --cnts[r + 1];
    }
    int currSum = 0;
    for (int i = 1; i < 200002; ++i)
    {
        currSum += cnts[i];
        cnts[i] = (currSum >= k);
    }
    for (int i = 1; i < 200002; ++i)
    {
        pfx[i] = pfx[i - 1] + cnts[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pfx[r + 1] - pfx[l] << '\n';
    }
}

int main()
{
    init();
    int t = 1;
    while (t--)
        solve();
    return 0;
}
