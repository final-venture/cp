#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// if a ship is hit, can take another turn only if opponent still has ships left
// First player starts, alternate turns. Even if opponent has no ships left, can still get a turn
// A draw occurs if not all ships have been sunk, or both sides are all sunk


// (0 indexed)
// r = h - 1 - y
// c = x


void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<int>> board1(h, vector<int>(w, 0));
    vector<vector<int>> board2(h, vector<int>(w, 0));
    int total1 = 0, total2 = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char x;
            cin >> x;
            if (x == '#') {
                board1[i][j] = 1;
                total1++;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char x;
            cin >> x;
            if (x == '#') {
                board2[i][j] = 1;
                total2++;
            }
        }
    }

    int turn1 = 1;
    int i = 0;
    for (; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        // cout << x << ' ' << y << '\n';

        int r = h - 1 - y, c = x;
        // cout << r << ' ' << c << '\n';

        if (turn1) {
            if (board2[r][c] == 0) {
                turn1 = 0;
            }
            else {
                board2[r][c] = 0;
                total2--;
            }
        }
        else {
            if (board1[r][c] == 0) {
                turn1 = 1;
            }
            else {
                board1[r][c] = 0;
                total1--;
            }
        }
        if (total1 == 0 || total2 == 0) {
            ++i;
            break;
        }
    }

    if (total2 == 0 && turn1) {
        // give player 2 another turn before we declare p1 wins.
        for (; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            int r = h - 1 - y, c = x;
            if (board1[r][c] == 0) {
                ++i;
                break;
            }
            else {
                board1[r][c] = 0;
                total1--;
            }
        }
    }

    // we can also draw when both are fully sunk
    if (total1 > 0 && total2 > 0) {
        cout << "draw" << '\n';
    }
    else if (total1 == 0 && total2 == 0) {
        cout << "draw" << '\n';
    }
    else if (total1 == 0) {
        cout << "player two wins" << '\n';
    }
    else if (total2 == 0) {
        cout << "player one wins" << '\n';
    }
    
    // the rest is garbage
    for (; i < n; ++i) {
        int x, y;
        cin >> x >> y;
    }
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
