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

int dp[66666];
int seg[400004];
vector<int> cakes;

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = dp[cakes[l]];
        return;
    }
    int mid = (l + r) / 2;
    int leftidx = idx * 2 + 1;
    int rightidx = idx * 2 + 2;
    build(leftidx, l, mid);
    build(rightidx, mid + 1, r);
    seg[idx] = seg[leftidx] ^ seg[rightidx];
}

void update(int idx, int l, int r, int targPos, int targVal)
{
    if (targPos < l || targPos > r) return;
    if (l == r && r == targPos)
    {
        seg[idx] = targVal;
        return;
    }
    int mid = (l + r) / 2;
    int leftidx = idx * 2 + 1;
    int rightidx = idx * 2 + 2;
    update(leftidx, l, mid, targPos, targVal);
    update(rightidx, mid + 1, r, targPos, targVal);
    seg[idx] = seg[leftidx] ^ seg[rightidx];
}

int query(int idx, int l, int r, int targL, int targR)
{
    if (targL > r || targR < l)
    {
        return -1;
    }
    if (targL <= l && r <= targR)
    {
        return seg[idx];
    }
    int mid = (l + r) / 2;
    int leftidx = idx * 2 + 1;
    int rightidx = idx * 2 + 2;
    int left = query(leftidx, l, mid, targL, targR);
    int right = query(rightidx, mid + 1, r, targL, targR);
    if (left == -1) return right;
    if (right == -1) return left;
    return left ^ right;
}

int mex(unordered_set<int> numSet)
{
    int x = 0;
    while (numSet.find(x) != numSet.end())
        x++;
    return x;
}

int setzero(int state, int rs, int re, int cs, int ce)
{
    bitset<16> s(state);
    for (int x = rs; x <= re; ++x) {
        for (int y = cs; y <= ce; ++y) {
            int pos = 15 - ((x * 4) + y);
            if (!s.test(pos)) {
                return -1;
            }
            s.reset(pos);
        }
    }
    int newState = s.to_ulong();
    return newState;
}

int grundy(int state)
{
    if (dp[state] != -1) return dp[state];
    unordered_set<int> pStates;
    for (int rs = 0; rs < 4; ++rs)
    {
        for (int re = rs; re < 4; ++re)
        {
            for (int cs = 0; cs < 4; ++cs)
            {
                for (int ce = cs; ce < 4; ++ce)
                {
                    int newState = setzero(state, rs, re, cs, ce);
                    if (newState == -1) continue;
                    pStates.insert(grundy(newState));
                }
            }
        }
    }
    return dp[state] = mex(pStates);
}

int readcake()
{
    string cake = "";
    for (int i = 0; i < 4; ++i)
    {
        string x;
        cin >> x;
        cake += x;
    }
    bitset<16> b(cake);
    return b.to_ulong();
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    grundy(65535);
    cakes = vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cakes[i] = readcake();
    }
    build(0, 0, n - 1);
    for (int i = 0; i < m; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int targL, targR;
            cin >> targL >> targR;
            --targL; --targR;
            int res = query(0, 0, n - 1, targL, targR);
            cout << ((res > 0) ? "Pishty" : "Lotsy") << '\n';
        }
        else // q == 2
        {
            int targPos;
            cin >> targPos;
            --targPos;
            int targVal = dp[readcake()];
            update(0, 0, n - 1, targPos, targVal);
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
