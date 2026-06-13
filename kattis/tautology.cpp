#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

string s;
unordered_map<char, int> mp {{'p', 0}, {'q', 1}, {'r', 2}, {'s', 3}, {'t', 4}};
vector<bool> val;
string conjunct = "KACE";
string vars = "pqrst";

// return [idxFinishedParsing, resultofParse]
pair<int, bool> parse(int idx) {
    if (s[idx] == 'N') {
        // cout << idx + 1 << ' ' << val[mp[s[idx + 1]]] << '\n';
        auto [finished, result] = parse(idx + 1);
        return {finished, result ^ 1};
    }
    if (vars.find(s[idx]) != string::npos) {
        // cout << idx << ' ' << val[mp[s[idx]]] << '\n';
        return {idx, val[mp[s[idx]]]};
    }
    if (conjunct.find(s[idx]) != string::npos) {
        auto [finished1, result1] = parse(idx + 1);
        auto [finished2, result2] = parse(finished1 + 1);
        if (s[idx] == 'K') {
            return {finished2, result1 & result2};
        }
        else if (s[idx] == 'A') {
            return {finished2, result1 | result2};
        }
        else if (s[idx] == 'C') {
            return {finished2, (result1 ^ 1) | (result2)};
        }
        else if (s[idx] == 'E') {
            return {finished2, 1 ^ result1 ^ result2};
        }
    }
}

void solve()
{
    val.resize(5);
    for (int i = 0; i < (1 << 5); ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((i >> j) & 1) {
                val[j] = true;
            }
            else {
                val[j] = false;
            }
        }
        auto [_, ret] = parse(0);
        if (ret == false) {
            cout << "not" << '\n';
            return;
        }
    }
    cout << "tautology" << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> s;
        if (s == "0") {
            break;
        }
        solve();
    }
    return 0;
}
