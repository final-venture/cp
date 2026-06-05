#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int r, c;

void solve()
{
    vector<string> a(c);
    for (int j = 0; j < r; ++j) {
        for (int i = 0; i < c; ++i) {
            char ch;
            cin >> ch;
            a[i].push_back(ch);
        }
    }

    stable_sort(a.begin(), a.end(), [](const string& s1, const string& s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        string l1 = s1;
        string l2 = s2;
        for (int i = 0; i < sz1; ++i) {
            if ('A' <= l1[i] && l1[i] <= 'Z') {
                l1[i] = tolower(l1[i]);
            }
        }
        for (int i = 0; i < sz2; ++i) {
            if ('A' <= l2[i] && l2[i] <= 'Z') {
                l2[i] = tolower(l2[i]);
            }
        }
        return l1 < l2;
    });

    for (int j = 0; j < r; ++j) {
        for (int i = 0; i < c; ++i) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> r >> c;
        if (r == 0 && c == 0) {
            break;
        }
        solve();
        cout << '\n';
    }
    return 0;
}
