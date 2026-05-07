#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n;
    cin >> n;
    int board[105][105];
    memset(board, 0, sizeof(board));
    vector<pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0;
    for (int _ = 0; _ < n; ++_)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i < x + 1; ++i)
        {
            for (int j = 1; j < y + 1; ++j)
            {
                board[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < 103; ++i)
    {
        for (int j = 1; j < 103; ++j)
        {
            if (!board[i][j] || board[i][j] == -1) continue;
            for (auto& [dx, dy] : dirs)
            {
                if (board[i + dx][j + dy] == 0)
                {
                    ++res;
                }
            }
        }
    }
    cout << res << '\n';
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
