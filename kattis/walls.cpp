#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

int l, w, n, r;
vector<pair<int, int>> wall;
const int FULL = 15;

int check(pair<int, int>& cen) {
    int ret = 0;
    auto [x, y] = cen;
    for (int i = 0; i < 4; ++i) {
        auto [wx, wy] = wall[i];
        int dx = abs(wx - x);
        int dy = abs(wy - y);
        int dist2 = dx*dx + dy*dy;
        if (dist2 <= r * r) {
            ret |= (1 << i);
        }
    }
    return ret;
}

void solve()
{
    cin >> l >> w >> n >> r;
    r *= 2; l *= 2; w *= 2;
    wall = {{-l/2, 0}, {l/2, 0}, {0, -w/2}, {0, w/2}};
    vector<pair<int, int>> centre(n);
    for (int i = 0; i < n; ++i) {
        cin >> centre[i].first >> centre[i].second;
        centre[i].first *= 2; centre[i].second *= 2;
    }

    int ret = 1e9;
    for (int a = 0; a < n; ++a) {
        int candA = check(centre[a]);
        if (candA == FULL) {
            ret = min(ret, 1);
        }
        for (int b = 0; b < n; ++b) {
            int candB = candA | check(centre[b]);
            if (candB == FULL) {
                ret = min(ret, 2);
            }
            for (int c = 0; c < n; ++c) {
                int candC = candB | check(centre[c]);
                if (candC == FULL) {
                    ret = min(ret, 3);
                }
                for (int d = 0; d < n; ++d) {
                    int candD = candC | check(centre[d]);
                    if (candD == FULL) {
                        ret = min(ret, 4);
                    }
                }
            }
        }
    }

    if (ret >= 1e9 - 2) {
        cout << "Impossible" << '\n';
    }
    else {
        cout << ret << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
