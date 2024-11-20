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

int city = -1;

bool solve()
{
    ++city;
    int n;
    int qst = 0;
    if (!(cin >> n)) return false;
    unordered_map<int, vector<int>> adjl{};
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        qst = max({qst, x, y});
        adjl[x].pb(y);
    }
    vector<vector<int>> adj(qst + 1, vector<int>(qst + 1, 0));
    for (auto& [from, neis] : adjl)
    {
        for (int nei : neis)
        {
            ++adj[from][nei];
        }
    }
    for (int via = 1; via < qst + 1; ++via)
    {
        for (int i = 0; i < qst + 1; ++i)
        {
            for (int j = 0; j < qst + 1; ++j)
            {
                adj[i][j] = adj[i][j] + adj[i][via] * adj[via][j];
            }
        }
    }

    for (int via = 1; via < qst + 1; ++via)
    {
        for (int i = 0; i < qst + 1; ++i)
        {
            for (int j = 0; j < qst + 1; ++j)
            {
                adj[i][j] = adj[i][j] + adj[i][via] * adj[via][j];
            }
        }
    }

    for (int x = 0; x < qst + 1; ++x)
    {
        if (adj[x][x])
        {

        }
    }

    cout << "matrix for city " << city << '\n';
    for (int i = 0; i < qst + 1; ++i)
    {
        for (int j = 0; j < qst + 1; ++j)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return true;
}

int main()
{
    init();
    while (solve());
    return 0;
}
