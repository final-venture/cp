#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}


unordered_map<int, pair<char, int>> c2p;
vector<pair<char, int>> res;
void dfs(int card)
{
    if (c2p.find(card) != c2p.end())
    {
        res.push_back(c2p[card]);
        dfs(c2p[card].second);
    }
}

void solve()
{
    res = {};
    c2p = {};
    int n;
    cin >> n;
    vector<vector<int>> cards(3, vector<int>(n + 1, 0));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            cin >> cards[i][j];
        }
    }
    string players = "qkj";
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    vector<int> mini(3, n);
    vector<int> cpar(3, n);

    pair<char, int> cand{'\0', 0};
    for (int i = 0; i < 3; ++i)
    {
        mini[i] = cards[i][n];
    }

    for (int j = n - 1; j >= 1; --j)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (cards[i][j] > mini[i])
            {
                dp[j] = 1;
                c2p[j] = {players[i], cpar[i]};
                break;
            }
        }
        if (dp[j])
        {
            for (int i = 0; i < 3; ++i)
            {
                if (cards[i][j] < mini[i])
                {
                    mini[i] = cards[i][j];
                    cpar[i] = j;
                }
            }
        }
    }

    cout << (dp[1] ? "YES" : "NO") << '\n';
    if (dp[1])
    {
        dfs(1);
        cout << res.size() << '\n';
        for (auto& [c, n] : res)
        {
            cout << c << ' ' << n << '\n';
        }
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
