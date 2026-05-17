#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> cnt1(26, 0);
vector<int> cnt2(cnt1);

int check()
{
    int tmp = 0;
    for (int c = 0; c < 26; ++c)
    {
        tmp += max(0, cnt1[c] - cnt2[c]);
    }
    return tmp;
}

void solve()
{
    int n, k;
    string s, res;
    cin >> n >> k;
    cin >> s;
    for (char c : s)
    {
        cnt1[c - 'a']++;
        cnt2[c - 'a']++;
    }
    int currChanges = 0;
    for (int i = 0; i < n; ++i)
    {
        --cnt1[s[i] - 'a'];
        if (currChanges == k)
        {
            res += s[i];
            continue;
        }
        for (int c = 0; c < 26; ++c)
        {
            if (!cnt2[c]) continue;
            --cnt2[c];
            if (c == s[i] - 'a')
            {
                res += s[i];
                break;
            }
            if (currChanges + check() + 1 <= k)
            {
                currChanges++;
                res += static_cast<char>(c + 'a');
                break;
            }
            ++cnt2[c];
        }
    }
    cout << res << '\n';
}

int main()
{
    init();
    solve();
    return 0;
}
