#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int N;

void solve()
{
    int s1 = 0, s2 = 0;
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        int qty;
        cin >> qty;
        if (cmd == "DROP") {
            cout << "DROP" << ' ' << 2 << ' ' << qty << '\n';
            s2 += qty;
        }
        else if (cmd == "TAKE") {
            int taken = 0;
            if (s1 - qty < 0) {
                if (s1 > 0) {
                    taken = s1;
                    cout << "TAKE " << 1 << ' ' << taken << '\n';
                }
                cout << "MOVE " << 2 << "->" << 1 << ' ' << s2 << '\n';
                s1 += s2;
                s2 = 0;
            }
            cout << "TAKE " << 1 << ' ' << qty - taken << '\n';
            s1 -= qty;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        solve();
        cout << '\n';
    }
    return 0;
}
