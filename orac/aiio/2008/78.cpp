#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9

const int inf = 1e9;

struct UF
{
    vector<int> par;
    vector<int> rank;

    UF(int n)
    {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
        }
    }

    int find(int x)
    {
        if (par[x] != x)
        {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void unionn(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return;
        if (rank[p1] < rank[p2])
        {
            par[p1] = par[p2];
        }
        else if (rank[p2] < rank[p1])
        {
            par[p2] = par[p1];
        }
        else
        {
            par[p2] = par[p1];
            ++rank[p1];
        }
    }
};

struct Track
{
    int x1, y1, x2, y2;
};

pair<int, int> intersect(Track &t1, Track &t2)
{
    if ((t1.x1 == t1.x2 && t2.x1 == t2.x2) || (t1.y1 == t1.y2 && t2.y1 == t2.y2))
    {
        return {inf, inf};
    }
    if (t1.x1 <= t2.x1 && t2.x1 <= t1.x2 && t2.y1 <= t1.y1 && t1.y1 <= t2.y2)
    {
        return {t2.x1, t1.y1};
    }
    if (t2.x1 <= t1.x1 && t1.x1 <= t2.x2 && t1.y1 <= t2.y1 && t2.y1 <= t1.y2)
    {
        return {t1.x1, t2.y1};
    }
    return {inf, inf};
}

int getDist(pair<int, int> &p)
{
    return (abs(p.first) + abs(p.second));
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    vector<Track> tracks;
    UF uf(n);
    for (int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        Track cand{x1, y1, x2, y2};
        for (int j = 0; j < tracks.size(); ++j)
        {
            pair<int, int> intersection_point = intersect(cand, tracks[j]);
            if (intersection_point.first != inf)
            {
                int dist = getDist(intersection_point);
                edges.push_back({dist, {i, j}});
            }
        }
        tracks.push_back(cand);
    }

    sort(edges.begin(), edges.end());
    int ret = 0;
    for (auto [dist, p] : edges)
    {
        auto &[u, v] = p;
        // cout << dist << ' ' << u << ' ' << v << '\n';
        if (uf.find(u) != uf.find(v))
        {
            uf.unionn(u, v);
        }
        else
        {
            ret += dist;
        }
    }

    cout << ret;

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < adj[i].size(); ++j)
    //     {
    //         cout << '{' << adj[i][j].first << ' ' << adj[i][j].second << '}' << ", ";
    //     }
    //     cout << '\n';
    // }
}

signed main()
{
#ifndef LOCAL
    freopen("trainin.txt", "r", stdin);
    freopen("trainout.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif
    solve();
    return 0;
}
