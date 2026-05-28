#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int N = 8;

void solve()
{
    // reverse rows but not cols
    // The black fields are filled with colons (“:”), white fields with dots (“.”).
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i + j) & 1) {
                grid[i][j] = ':';
            }
            else {
                grid[i][j] = '.';
            }
        }
    }

    string whiteRaw;
    getline(cin, whiteRaw);
    string blackRaw;
    getline(cin, blackRaw);

    stringstream wh(whiteRaw);
    stringstream bl(blackRaw);
    wh.ignore(10, ':');
    wh >> ws;
    bl.ignore(10, ':');
    bl >> ws;
    string curr;

    while (getline(wh, curr, ',')) {
        char type = 'P';
        int row, col;
        if (curr.size() == 2) {
            col = (curr[0] - 'a');
            row = 8 - (curr[1] - '0');
        }
        else if (curr.size() == 3) {
            type = curr[0];
            col = (curr[1] - 'a');
            row = 8 - (curr[2] - '0');
        }
        
        grid[row][col] = toupper(type);
    }

    while (getline(bl, curr, ',')) {
        char type = 'P';
        int row, col;
        if (curr.size() == 2) {
            col = (curr[0] - 'a');
            row = 8 - (curr[1] - '0');
        }
        else if (curr.size() == 3) {
            type = curr[0];
            col = (curr[1] - 'a');
            row = 8 - (curr[2] - '0');
        }
        
        grid[row][col] = tolower(type);
    }

    // print '|' on 0, 4, 8, 12... on odd rows              (all j which are multiples of 4)
    // print '.' on 1, 3, 9, 11, 17, 19, ... on odd rows    (odd numbers j where j / 4 is even)
    // print ':' on 5, 7, 13, 15... on odd rows             (odd numbers j where j / 4 is odd)
    // print grid[i/2][j/4] 2, 6, 10... on odd rows         (the rest).
    
    // print '+' on 0, 4, 8, 12... in even rows
    // print '-' on the remaining in even rows.
    // Solution: in even rows we can just print the whole row at once.

    int invert = 1;
    for (int i = 0; i < N * 2 + 1; ++i) {
        if (i & 1) {
            invert ^= 1;
            for (int j = 0; j < N * 4 + 1; ++j) {
                if (j % 4 == 0) {
                    cout << '|';
                }
                else if (j & 1 && (j / 4) & 1) {
                    if (invert) {
                        cout << '.';
                    }
                    else {
                        cout << ':';
                    }
                }
                else if (j & 1) {
                    if (invert) {
                        cout << ':';
                    }
                    else {
                        cout << '.';
                    }
                }
                else {
                    cout << grid[i/2][j/4];
                }
            }
            cout << '\n';
        }
        else {
            cout << "+---+---+---+---+---+---+---+---+" << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
