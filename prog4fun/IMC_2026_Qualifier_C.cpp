#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int SIZE = 2222;

int diff[SIZE][SIZE] = {0};
int n, q;

pair<int, int> transform(int x, int y) {
    return {x + y, x - y + 1111};
}

void clamp(int& x, int& y) {
    x = max(1LL, x);
    x = min(2200LL, x);
    y = max(1LL, y);
    y = min(2200LL, y);
}

void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x, y, v, r;
        cin >> x >> y >> v >> r;
        auto [newX, newY] = transform(x, y);

        // top left, top right, bottom left, bottom right TO UPDATE.
        int tlX = newX - r, tlY = newY - r;
        clamp(tlX, tlY);
        int trX = newX - r, trY = newY + r + 1;
        clamp(trX, trY);
        int blX = newX + r + 1, blY = newY - r;
        clamp(blX, blY);
        int brX = newX + r + 1, brY = newY + r + 1;
        clamp(brX, brY);

        diff[tlX][tlY] += v;
        diff[trX][trY] -= v;
        diff[blX][blY] -= v;
        diff[brX][brY] += v;
    }

    for (int i = 1; i < SIZE; ++i) {
        for (int j = 1; j < SIZE; ++j) {
            diff[i][j] = diff[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }

    while (q--) {
        int qx, qy;
        cin >> qx >> qy;
        auto [newQx, newQy] = transform(qx, qy);
        cout << diff[newQx][newQy] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
