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
    vector<int> a(n + 1);
    vector<pair<int, int>> resvec;
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
    }
    set<int> pos1;
    for (int i = 1; i < n + 1; ++i)
    {
        if (a[i] == 1)
        {
            pos1.insert(i);
        }
    }
    int l = 1;
    int r = n;
    while (l < r)
    {
        if (a[l] == 0)
        {
            ++l;
            continue;
        }
        while (l < r && a[r] != 0)
        {
            --r;
        }
        if (l >= r)
        {
            break;
        }
        if (a[l] == 1)
        {
            swap(a[l], a[r]);
            resvec.push_back({l, r});
            pos1.erase(l);
            pos1.insert(r);
        }
        else
        {
            int idx1 = *pos1.rbegin();
            swap(a[l], a[idx1]);
            resvec.push_back({l, idx1});
            swap(a[l], a[r]);
            resvec.push_back({l, r});
            pos1.erase(idx1);
            pos1.insert(r);
        }
        ++l;
    }
    l = 1;
    while (l < *pos1.rbegin())
    {
        while (l < *pos1.rbegin() && a[l] != 2)
        {
            ++l;
            continue;
        }
        if (l >= *pos1.rbegin())
        {
            break;
        }
        int idx1 = *pos1.rbegin();
        swap(a[l], a[idx1]);
        resvec.push_back({l, idx1});
        pos1.erase(idx1);
        pos1.insert(l);
        ++l;
    }
    cout << resvec.size() << '\n';
    for (auto& [x, y] : resvec) cout << x << ' ' << y << '\n';
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
