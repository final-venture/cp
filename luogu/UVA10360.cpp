#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXDIM = 1025;

int d, n;
int grid[MAXDIM + 5][MAXDIM + 5];

void solve()
{
    memset(grid, 0, sizeof(grid));
    cin >> d >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, cnt;
        cin >> x >> y >> cnt;
        int tl_x = max(0LL, x - d);
        int br_x = min(1024LL, x + d);
        int tl_y = max(0LL, y - d);
        int br_y = min(1024LL, y + d);
        
        for (int j = tl_x; j <= br_x; ++j) {
            for (int k = tl_y; k <= br_y; ++k) {
                grid[j][k] += cnt;
            }
        }
    }

    int retCnt = 0, retX = -1, retY = -1;
    for (int i = 0; i < MAXDIM; ++i) {
        for (int j = 0; j < MAXDIM; ++j) {
            if (grid[i][j] > retCnt) {
                retCnt = grid[i][j];
                retX = i;
                retY = j;
            }
        }
    }
    cout << retX << ' ' << retY << ' ' << retCnt << '\n';
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
