#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<string> strs;
    // split into s[0..i], s[i + 1..j], s[j + 1..n - 1]
    for (int i = 0; i <= n - 3; ++i) {
        for (int j = i + 1; j <= n - 2; ++j) {
            string s1 = s.substr(0, i + 1);
            reverse(s1.begin(), s1.end());
            string s2 = s.substr(i + 1, j - (i + 1) + 1);
            reverse(s2.begin(), s2.end());
            string s3 = s.substr(j + 1, (n - 1) - (j + 1) + 1);
            reverse(s3.begin(), s3.end());
            strs.push_back(s1 + s2 + s3);
        }
    }
    sort(strs.begin(), strs.end());
    cout << strs[0] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
