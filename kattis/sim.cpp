#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string s;
    getline(cin, s);
    list<char> ret;
    int sz = s.size();
    auto curr = ret.begin();
    for (int i = 0; i < sz; ++i) {
        if (s[i] == '[') {
            curr = ret.begin();
        }
        else if (s[i] == ']') {
            curr = ret.end();
        }
        else if (s[i] == '<') {
            if (curr != ret.begin()) {
                auto toRemove = curr;
                --toRemove;
                ret.erase(toRemove);
            }
        }
        else {
            ret.insert(curr, s[i]);
        }
    }

    for (auto x : ret) {
        cout << x;
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);
    while (t--)
        solve();
    return 0;
}
