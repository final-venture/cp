#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int guess;
string garb, resp;

void solve()
{
    bool first = true;
    int lb = 1, ub = 10;
    while (first || cin >> guess) {
        first = false;
        cin >> garb >> resp;
        if (resp == "high") {
            ub = min(ub, guess - 1);
        }
        else if (resp == "low") {
            lb = max(lb, guess + 1);
        }
        else if (resp == "on") {
            if (lb <= ub && lb <= guess && guess <= ub) {
                cout << "Stan may be honest" << '\n';
            }
            else {
                cout << "Stan is dishonest" << '\n';
            }
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> guess;
        if (guess == 0) {
            break;
        }
        solve();
    }
    return 0;
}
