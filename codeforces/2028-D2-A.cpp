#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
int t, n, a, b;
unordered_map<char, pair<int, int>> c2d{{'N', {0, 1}}, {'S', {0, -1}}, {'W', {-1, 0}}, {'E', {1, 0}}};

void solve()
{
    int x = 0, y = 0;
    cin >> n >> a >> b;
    vector<pair<int, int>> dirs;
    char dir;
    while (n--)
    {
        cin >> dir;
        dirs.push_back(c2d[dir]);
    }
    for (int i = 0; i < 25; ++i)
    {
        for (auto &[dx, dy] : dirs)
        {
            x += dx;
            y += dy;
            if (x == a && y == b)
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
