#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const string vowels = "aeiouy";

void solve()
{
    string s;
    while (cin >> s) {
        if (vowels.find(s[0]) != string::npos) {
            cout << s << "yay" << ' ';
            continue;
        }

        int sz = s.size();
        string buffer;
        int ok = 0;
        for (int i = 0; i < sz; ++i) {
            if (ok || vowels.find(s[i]) != string::npos) {
                cout << s[i];
                ok = 1;
            }
            else {
                buffer.push_back(s[i]);
            }
        }
        for (auto x : buffer) {
            cout << x;
        }
        cout << "ay" << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
