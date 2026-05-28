#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// can't have both O and X in winning states
// out of all winning states of O, or X, there must be one common factor between them
// This must be satisfied: cnt[O] == cnt[X] - 1 OR cnt[O] == cnt[X]

void solve()
{
    vector<vector<char>> grid(3, vector<char>(3));
    int cntO = 0, cntX = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'O') {
                cntO++;
            }
            else if (grid[i][j] == 'X') {
                cntX++;
            }
        }
    }
    if (cntO != cntX - 1 && cntO != cntX) {
        cout << "no" << '\n';
        return;
    }

    // hash = 3 * r + c
    unordered_set<int> winningXRow, winningORow;
    int winX = 0, winO = 0;
    for (int i = 0; i < 3; ++i) {
        // check rows
        if (grid[i][0] == 'X' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            for (int j = 0; j < 3; ++j) {
                winningXRow.insert(3 * i + j);
            }
            winX = 1;
        }
        else if (grid[i][0] == 'O' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            for (int j = 0; j < 3; ++j) {
                winningORow.insert(3 * i + j);
            }
            winO = 1;
        }
    }

    unordered_set<int> winningXCol, winningOCol;
    for (int j = 0; j < 3; ++j) {
        // check cols
        if (grid[0][j] == 'X' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            for (int i = 0; i < 3; ++i) {
                winningXCol.insert(3 * i + j);
            }
            winX = 1;
        }
        else if (grid[0][j] == 'O' && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            for (int i = 0; i < 3; ++i) {
                winningOCol.insert(3 * i + j);
            }
            winO = 1;
        }
    }
    unordered_set<int> winningXDiag, winningODiag;
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        if (grid[0][0] == 'X') {
            winningXDiag.insert(0);
            winningXDiag.insert(4);
            winningXDiag.insert(8);
            winX = 1;
        }
        else if (grid[0][0] == 'O') {
            winningODiag.insert(0);
            winningODiag.insert(4);
            winningODiag.insert(8);
            winO = 1;
        }
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        if (grid[0][2] == 'X') {
            winningXDiag.insert(2);
            winningXDiag.insert(4);
            winningXDiag.insert(6);
            winX = 1;
        }
        else if (grid[0][2] == 'O') {
            winningODiag.insert(2);
            winningODiag.insert(4);
            winningODiag.insert(6);
            winO = 1;
        }
    }

    if (winO && winX) {
        cout << "no" << '\n';
        return;
    }
    if (!winO && !winX) {
        cout << "yes" << '\n';
        return;
    }

    unordered_set<int> inter;
    int dump = 1;
    if (winO) {
        if (cntX != cntO) {
            cout << "no" << '\n';
            return;
        }
        unordered_set<int> newInter;
        if (!winningODiag.empty()) {
            for (auto x : winningODiag) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
        if (!winningOCol.empty()) {
            for (auto x : winningOCol) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
        if (!winningORow.empty()) {
            for (auto x : winningORow) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
    }
    else if (winX) {
        if (cntX != cntO + 1) {
            cout << "no" << '\n';
            return;
        }
        unordered_set<int> newInter;
        if (!winningXDiag.empty()) {
            for (auto x : winningXDiag) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
        if (!winningXCol.empty()) {
            for (auto x : winningXCol) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
        if (!winningXRow.empty()) {
            for (auto x : winningXRow) {
                if (dump || inter.contains(x)) {
                    newInter.insert(x);
                }
            }
            dump = 0;
            inter = newInter;
        }
    }

    if (inter.empty()) {
        cout << "no" << '\n';
    }
    else {
        cout << "yes" << '\n';
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
