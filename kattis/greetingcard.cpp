#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

bool check(int x1, int y1, int x2, int y2) {
    int targ = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (2018 * 2018 == targ) {
        return true;
    }
    return false;
}

const vector<pair<int, int>> neis {
    {-2018, 0}, 
    {-1680, -1118}, 
    {-1680, 1118}, 
    {-1118, -1680}, 
    {-1118, 1680}, 
    {0, -2018}, 
    {0, 2018}, 
    {1118, -1680}, 
    {1118, 1680}, 
    {1680, -1118}, 
    {1680, 1118}, 
    {2018, 0}, 
};

unordered_map<int, int> cnt;
const int INF = 1e9;

void solve()
{
    int n;
    cin >> n;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        int oKey = x * INF + y;

        ret += cnt[oKey];

        for (auto& [dx, dy] : neis) {
            int dKey = dx * INF + dy;
            cnt[oKey + dKey]++;
        }
    }
    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
