#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const vector<string> rows {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

unordered_map<char, pair<int, int>> c2c;

int getDist(string& s1, string& s2) {
    int ret = 0;
    for (int i = 0; i < s1.size(); ++i) {
        ret += abs(c2c[s1[i]].first - c2c[s2[i]].first) + abs(c2c[s1[i]].second - c2c[s2[i]].second);
    }
    return ret;
}

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < rows.size(); ++i) {
        for (int j = 0; j < rows[i].size(); ++j) {
            c2c[rows[i][j]] = {i, j};
       }
    }
    int l;
    cin >> l;

    vector<pair<string, int>> ret(l);
    for (int i = 0; i < l; ++i) {
        string s_;
        cin >> s_;
        int dist = getDist(s, s_);
        ret[i] = {s_, dist};
    }

    sort(ret.begin(), ret.end(), [](auto& p1, auto& p2) {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    });
    for (auto& [str, dist] : ret) {
        cout << str << ' ' << dist << '\n';
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
