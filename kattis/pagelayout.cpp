#include <bits/stdc++.h>

using namespace std;

int n;
int FULL;
vector<vector<bool>> cross;
vector<tuple<int, int, int, int>> rct;

int dfs(int idx, int mask) {
    if (idx >= n) {
        return 0;
    }
    int take = -1;
    for (int bit = 0; bit < n; ++bit) {
        if (1 & (mask >> bit)) {
            if (cross[idx][bit]) {
                take = 0;
            }
        }
    }
    if (take == -1) {
        int currArea = get<0>(rct[idx]) * get<1>(rct[idx]);
        int newMask = mask | (1 << idx);
        take = currArea + dfs(idx + 1, newMask);
    }
    int notTake = dfs(idx + 1, mask);
    return max(take, notTake);
}

void solve()
{
    rct.resize(n);
    FULL = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        int w, h, x, y;
        cin >> w >> h >> x >> y;
        rct[i] = {w, h, x, y};
    }
    cross.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto& [w1, h1, x1, y1] = rct[i];
            auto& [w2, h2, x2, y2] = rct[j];
            if (((y1 <= y2 && y2 < y1 + h1) || (y2 <= y1 && y1 < y2 + h2)) && 
                    ((x2 <= x1 && x1 < w2 + x2) || (x1 <= x2 && x2 < w1 + x1))) {
                cross[i][j] = true;
            }
        }
    }
    cout << dfs(0, 0) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        solve();
    }
    return 0;
}
