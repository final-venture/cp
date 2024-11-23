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

int msb(int num) {
    return (int)log2(num);
}

void solve()
{
    vector<vector<int>> buckets(80, vector<int> {});
    int n;
    cin >> n;
    vector<int> modin;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        buckets[msb(x)].pb(x);
    }

    for (int i = 79; i >= 0; --i)
    {
        if (buckets[i].empty()) continue;
        int cand = buckets[i].back();
        buckets[i].pop_back();
        modin.pb(cand);
        while (!buckets[i].empty())
        {
            int b = buckets[i].back();
            buckets[i].pop_back();
            int p = b ^ cand;
            if (p)
                buckets[msb(p)].pb(p);
        }
    }

    int res = 0;
    for (int b : modin)
    {
        if ((res ^ b) > res) res = res ^ b;
    }
    cout << res;
}

int main()
{
    init();
    solve();
    return 0;
}
