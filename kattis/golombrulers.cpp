#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXA = 2005;

void solve()
{
    string line;
    while (getline(cin, line)) {
        vector<int> a;
        int x;
        stringstream ss(line);
        while (ss >> x) {
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> reach(a.back() + 1, 0);
        int ok = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (reach[a[j] - a[i]]) {
                    cout << "not a ruler" << '\n';
                    ok = 0;
                    break;
                }
                reach[a[j] - a[i]] = 1;
            }
            if (!ok) {
                break;
            }
        }
        if (!ok) {
            continue;
        }

        vector<int> missing;
        for (int i = 1; i < a.back() + 1; ++i) {
            if (reach[i] == 0) {
                missing.push_back(i);
            }
        }
        if (missing.empty()) {
            cout << "perfect" << '\n';
        }
        else {
            cout << "missing ";
            for (auto x : missing) {
                cout << x << ' ';
            }
            cout << '\n';
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
