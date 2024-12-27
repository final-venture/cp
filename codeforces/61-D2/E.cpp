#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9
#define int ll

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<int> seg;
 
void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = 0;
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
}
 
int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (qr < l || r < ql)
    {
        return 0;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return left + right;
}
 
int update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = 1;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = update(idx * 2 + 1, l, m, t, v);
    int right = update(idx * 2 + 2, m + 1, r, t, v);
    return seg[idx] = left + right;
}

void solve()
{
    int n;
    cin >> n;
    seg.resize(4 * n);
    vector<int> aa(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> aa[i];
    }
    vector<int> aaa(aa.begin(), aa.end());
    sort(aaa.begin(), aaa.end(), greater<>());

    map<int, int> n2i; // unordered faster
    for (int i = 0; i < n; ++i)
    {
        n2i[aaa[i]] = i;
    }

    build(0, 0, n - 1);
    vector<int> pfxgt(n);
    pfxgt[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        pfxgt[i] = (i - 1 < 0) ? 0 : query(0, 0, n - 1, 0, n2i[aa[i]] - 1);
        update(0, 0, n - 1, n2i[aa[i]], 1);
        // cout << i << " : " << pfxgt[i] << '\n';
        // cout << "UPD " << n2i[aa[i]];
        // cout << x << endl;
    }
    vector<int> sfxlt(n);
    for (int i = n - 1; i >= 0; --i)
    {
        int pfxlt = i - pfxgt[i];
        sfxlt[i] = n - 1 - n2i[aa[i]] - pfxlt;
    }
    
    // cout << pfxgt.size() << '\n';
    // cout << sfxlt.size() << '\n';

    // for (int x : sfxlt) cout << x << ' ';
        // cout << '\n';
    // for (int x : pfxgt) cout << x << ' ';

    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += (pfxgt[i] * sfxlt[i]);
    }
    cout << ret << '\n';
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
