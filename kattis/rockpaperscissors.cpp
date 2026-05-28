#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

inline int checkWin1(string& m1, string& m2) {
    if (m1 == "paper" && m2 == "rock") {
        return 1;
    }
    else if (m1 == "rock" && m2 == "scissors") {
        return 1;
    }
    else if (m1 == "scissors" && m2 == "paper") {
        return 1;
    }
    else if (m1 == m2) {
        return -1;
    }
    return 0;
}

int n, k;

void solve()
{
    cin >> k;
    int games = (k*n*(n-1)) / 2;
    vector<int> win(n + 1, 0);
    vector<int> loss(n + 1, 0);
    for (int i = 0; i < games; ++i) {
        int p1, p2;
        string m1, m2;
        cin >> p1 >> m1 >> p2 >> m2;
        if (checkWin1(m1, m2) == 1) {
            win[p1]++;
            loss[p2]++;
        }
        else if (checkWin1(m1, m2) == 0) {
            win[p2]++;
            loss[p1]++;
        }
        else {
            continue;
        }
    }

    cout << fixed << setprecision(3);
    for (int i = 1; i <= n; ++i) {
        if (win[i] == 0 && loss[i] == 0) {
            cout << '-' << '\n';
            continue;
        }
        cout << (double)win[i] / (win[i] + loss[i]) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << '\n';
        solve();
    }
    return 0;
}
