#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N, H;
    cin >> N >> H;
    vector<int> cntb(H + 5, 0), cntt(H + 5, 0);
    int isDown = 1;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (isDown) {
            ++cntb[x];
        }
        else {
            ++cntt[x];
        }
        isDown ^= 1;
    }
    for (int i = 1; i <= H + 3; ++i) {
        cntb[i] += cntb[i - 1];
        cntt[i] += cntt[i - 1];
    }

    // for (auto x : cntb) {
    //     cout << x << ' ';
    // }
    // cout << '\n';
    // for (auto x : cntt) {
    //     cout << x << ' ';
    // }
    // cout << '\n';

    // change bounds
    int minCol = 1e9;
    int minCnt = 0;
    for (int i = 1; i <= H; ++i) {
        int fromTop = H - i + 1;
        int fromBot = i;

        int candCol = (N / 2 - cntb[fromBot - 1]) + (N / 2 - cntt[fromTop - 1]);
        if (candCol < minCol) {
            minCol = candCol;
            minCnt = 1;
            // cerr << i << ' ';
            // cerr << candCol << '\n';
        }
        else if (candCol == minCol) {
            minCnt++;
            // cerr << i << ' ';
            // cerr << candCol << '\n';
        }
    }

    cout << minCol << ' ' << minCnt << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
