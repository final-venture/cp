#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

char type;

struct Data {
    string& s;
    vector<vector<bool>>& grid;
    int& timer;
};

void D2B(int sr, int sc, int er, int ec, Data& data) {
    char ch;
    cin >> ch;
    if (ch == 'D') {
        D2B(sr, sc, (er + sr) / 2, (ec + sc) / 2, data);
        if (sc != ec) {
            D2B(sr, (ec + sc) / 2 + 1, (er + sr) / 2, ec, data);
        }
        if (sr != er) {
            D2B((er + sr) / 2 + 1, sc, er, (ec + sc) / 2, data);
        }
        if (sr != er && sc != ec) {
            D2B((er + sr) / 2 + 1, (ec + sc) / 2 + 1, er, ec, data);
        }
    }
    else {
        for (int i = sr; i <= er; ++i) {
            for (int j = sc; j <= ec; ++j) {
                data.grid[i][j] = ch - '0';
            }
        }
    }
}

void B2D(int sr, int sc, int er, int ec, Data& data) {
    int ok = data.grid[sr][sc];
    for (int i = sr; i <= er; ++i) {
        for (int j = sc; j <= ec; ++j) {
            if (ok != data.grid[i][j]) {
                ok = -1;
                break;
            }
        }
    }
    if (ok != -1) {
        data.s.push_back(ok + '0');
    }
    else {
        data.s.push_back('D');
        B2D(sr, sc, (er + sr) / 2, (ec + sc) / 2, data);
        if (sc != ec) {
            B2D(sr, (ec + sc) / 2 + 1, (er + sr) / 2, ec, data);
        }
        if (sr != er) {
            B2D((er + sr) / 2 + 1, sc, er, (ec + sc) / 2, data);
        }
        if (sr != er && sc != ec) {
            B2D((er + sr) / 2 + 1, (ec + sc) / 2 + 1, er, ec, data);
        }
    }
}

void solve()
{
    int rows, cols;
    cin >> rows >> cols;
    string s;
    if (type == 'D') {
        vector<vector<bool>> grid(rows, vector<bool>(cols));
        int timer = 0;
        Data data {s, grid, timer};
        D2B(0, 0, rows - 1, cols - 1, data);
        cout << 'B' << right << setw(4) << rows << right << setw(4) << cols << '\n';
        int print_cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << grid[i][j];
                print_cnt++;
                if (print_cnt == 50) {
                    cout << '\n';
                    print_cnt = 0;
                }
            }
        }
        if (print_cnt != 0) cout << '\n';
    }
    else if (type == 'B') {
        vector<vector<bool>> grid(rows, vector<bool>(cols));
        for (int i = 0; i < rows * cols; ++i) {
            char ch; 
            cin >> ch;
            grid[i / cols][i % cols] = ch - '0';
        }
        int timer = 0;
        string ret;
        Data data {ret, grid, timer};
        B2D(0, 0, rows - 1, cols - 1, data);
        cout << 'D' << right << setw(4) << rows << right << setw(4) << cols << '\n';
        for (int i = 0; i < ret.size(); ++i) {
            cout << ret[i];
            if ((i + 1) % 50 == 0) cout << '\n';
        }
        if (ret.size() % 50 != 0) cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> type && type != '#') {
        solve();
    }
    return 0;
}
