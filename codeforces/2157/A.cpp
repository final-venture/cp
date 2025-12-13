#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

int n;
vector<int> cnts;

void solve()
{
    cin >> n;
    cnts.assign(n + 2, 0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++cnts[x];
    }
    int ret = 0;
    for (int i = 0; i < n + 2; ++i)
    {
        if (cnts[i] > i)
        {
            ret += cnts[i] - i;
        }
        else if (cnts[i] < i)
        {
            ret += cnts[i];
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
