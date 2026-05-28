#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    char st_r_;
    int st_c;
    cin >> st_r_ >> st_c;
    int st_r = st_r_ - 'A' + 1;

    char ed_r_;
    int ed_c;
    cin >> ed_r_ >> ed_c;
    int ed_r = ed_r_ - 'A' + 1;

    // impossible
    if (abs(st_r - st_c) % 2 != abs(ed_r - ed_c) % 2) {
        cout << "Impossible" << '\n';
        return;
    }

    if (ed_r == st_r && ed_c == st_c) {
        cout << 0 << ' ' << st_r_ << ' ' << st_c << '\n';
        return;
    } 

    if (abs(ed_r - st_r) == abs(ed_c - st_c)) {
        cout << 1 << ' ' << st_r_ << ' ' << st_c << ' ' << ed_r_ << ' ' << ed_c << '\n';
        return;
    }

    for (int dr = -10; dr < 10; ++dr) {
        int nr = st_r + dr;
        char nr_ = nr + 'A' - 1;

        // case 1: dr == dc
        int dc = dr;
        int nc = st_c + dc;

        if (1 <= nr && nr <= 8 && 1 <= nc && nc <= 8) {
            if (abs(ed_r - nr) == abs(ed_c - nc)) {
                cout << 2 << ' ' << st_r_ << ' ' << st_c << ' ' << nr_ << ' ' << nc << ' ' << ed_r_ << ' ' << ed_c << '\n';
                return;
            }
        }

        // case 2: dr == -dc
        dc = -dr;
        nc = st_c + dc;

        if (1 <= nr && nr <= 8 && 1 <= nc && nc <= 8) {
            if (abs(ed_r - nr) == abs(ed_c - nc)) {
                cout << 2 << ' ' << st_r_ << ' ' << st_c << ' ' << nr_ << ' ' << nc << ' ' << ed_r_ << ' ' << ed_c << '\n';
                return;
            }   
        }
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
