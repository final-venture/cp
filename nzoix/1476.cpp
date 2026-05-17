#include <bits/stdc++.h>

using namespace std;

vector<int> seg;
vector<int> arr;

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (l > qr || r < ql)
    {
        return INT_MIN;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2, l, m, ql, qr);
    int right = query(idx * 2 + 1, m + 1, r, ql, qr);
    return max(left, right);
}

void update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = v;
        arr[t] = v;
        return;
    }
    if (r < t || l > t)
    {
        return;
    }
    int m = l + (r - l) / 2;
    update(idx * 2, l, m, t, v);
    update(idx * 2 + 1, m + 1, r, t, v);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = arr[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    arr.resize(n + 1);
    seg.resize(4 * n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    build(1, 1, n);

    long long prev = 0;
    long long ret = 0;
    vector<pair<int, pair<int, int>>> queries(m);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        queries[i] = {b, {a, c}}; // dist, {person, new speed}
    }

    int currupd = 0;
    while (currupd < m)
    {
        int curr_dist = queries[currupd].first;
        int curr_person = queries[currupd].second.first;
        int curr_speed = queries[currupd].second.second;

        long long dist_to_walk = min((long long)curr_dist, (long long)l) - prev;
        long long minspd = query(1, 1, n, 1, n);
        ret += minspd * dist_to_walk;

        update(1, 1, n, curr_person, curr_speed);

        prev = min((long long)curr_dist, (long long)l);
        ++currupd;
    }
    if (prev < l)
    {
        long long dist_to_walk = l - prev;
        long long minspd = query(1, 1, n, 1, n);
        ret += minspd * dist_to_walk;
    }

    cout << ret << '\n';
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
