#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// C(allow, wo) = all
// reverse the 2nd word: allow, ow
// if one string is a substring of the other, then return the part that is not common.

// C(allow, wot) = allt
// reverse the 2nd word: allow, tow
// length is just len(a) + len(b) - 2 * len(longest common suffix).

// So the result is: 
//  (2 * n * len(i) for all i) - 2 * sum of longest common prefix for all pairs.
// The latter can be computed by iterating through all prefixes of every reversed word
//  and finding the count that has this prefix common in a trie.

const int MAXN = 1e6;

int32_t trie[MAXN + 5][26];
int32_t pfxCnt[MAXN + 5];
int32_t timer = 0;

void add(string& s) {
    int sz = s.size();
    int idx = 0;

    int curr = 0;

    while (idx < sz) {
        int c = s[idx] - 'a';
        if (trie[curr][c] == 0) {
            trie[curr][c] = ++timer;
        }
        curr = trie[curr][c];
        ++pfxCnt[curr];
        ++idx;
    }
}

int getPfxCnt(string& s) {
    int ret = 0;
    int sz = s.size();
    int idx = 0;

    int curr = 0;

    while (idx < sz) {
        int c = s[idx] - 'a';
        if (trie[curr][c] == 0) {
            break;
        }
        curr = trie[curr][c];
        ret += pfxCnt[curr];
        ++idx;
    }

    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            trie[i][j] = 0;
        }
        pfxCnt[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        add(s[i]);
    }

    for (int i = 0; i < n; ++i) {
        reverse(s[i].begin(), s[i].end());
    }

    int lcpSum = 0;
    for (int i = 0; i < n; ++i) {
        lcpSum += getPfxCnt(s[i]);
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int sz = s[i].size();
        ret += 2 * n * sz;
    }

    cout << ret - 2 * lcpSum << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
