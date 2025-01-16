#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
// #define int ll

void solve()
{
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    map<int, vector<pair<int, int>>> merged;
    for (int i = 0; i < k; ++i)
    {
        int a, b, c; // day, musician idx, chg
        cin >> a >> b >> c;
        merged[a].push_back({b, c});
    }

    pair<int, int> ret = {0, INT_MIN};
    int prev_chg = 0;
    int prev_time = 0;
    int running = 0;
    vector<int> lst(n + 1, 0);

    for (auto &[curr_time, vec] : merged)
    {
        int prev = (curr_time - 1 - prev_time) * prev_chg + running;
        int curr_chg = prev_chg;
        for (auto &[idx, dchg] : vec)
        {
            curr_chg += (dchg - lst[idx]);
            lst[idx] = dchg;
        }
        int total = curr_chg + prev;
        if (prev >= ret.second)
        {
            ret = {curr_time - 1, prev};
        }
        if (total >= ret.second)
        {
            ret = {curr_time, total};
        }

        prev_chg = curr_chg;
        prev_time = curr_time;
        running = total;
    }

    int tmp = (t - prev_time) * prev_chg + running;
    if (tmp >= ret.second)
    {
        ret = {t, tmp};
    }

    cout << ret.first << ' ' << ret.second;
}

signed main()
{
#ifndef LOCAL
    freopen("divain.txt", "r", stdin);
    freopen("divaout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
