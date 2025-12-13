#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

unordered_map<char, pair<int, int>> dirs{{'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};

void solve()
{
    int n, k, w, h;
    cin >> n >> k >> w >> h;
    string s;
    cin >> s;

    int H = 2 * h, W = 2 * w;

    int r = 0, c = 0;
    map<pair<int, int>, int> end2cnt;
    for (int i = 0; i < s.size(); ++i)
    {
        auto [dr, dc] = dirs[s[i]];
        r += dr;
        c += dc;

        ++end2cnt[{(r % H + H) % H, (c % W + W) % W}]; // mod first to get modded negative value, then add mod and mod again for case of positive value
    }

    int chg_r = (r % H + H) % H;
    int chg_c = (c % W + W) % W;

    int ret = 0;
    int iter_r = 0, iter_c = 0;
    for (int i = 0; i < k; ++i)
    {
        ret += end2cnt[{(H - iter_r) % H, (W - iter_c) % W}];
        iter_r += chg_r;
        iter_c += chg_c;
        iter_r %= H;
        iter_c %= W;
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
