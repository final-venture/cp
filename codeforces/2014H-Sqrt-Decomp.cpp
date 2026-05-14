#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MAXA = 1e6;
const int MAXN = 2e5;

int n, q;
int a[MAXN + 1];
int num2cnt[MAXA + 1];
int odd_cnt;

void add_win(int idx) {
    num2cnt[a[idx]]++;
    if (num2cnt[a[idx]] & 1) {
        ++odd_cnt;
    }
    else {
        --odd_cnt;
    }
}

void remove_win(int idx) {
    num2cnt[a[idx]]--;
    if (num2cnt[a[idx]] & 1) {
        ++odd_cnt;
    }
    else {
        --odd_cnt;
    }
}

void solve()
{
    odd_cnt = 0;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        num2cnt[a[i]] = 0;
    }

    vector<pair<pair<int, int>, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    int SQRT = sqrtl(n);
    // sort queries [l, r] primarily based on the block that l is in,
    // and secondarily based on the value of r ascending.
    sort(queries.begin(), queries.end(), [&] (pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
        if (p1.first.first / SQRT != p2.first.first / SQRT) {
            return p1.first.first < p2.first.first;
        }
        else {
            return p1.first.second < p2.first.second;
        }
    });

    // window indices
    vector<bool> ret(q);
    int win_l = 0, win_r = -1;
    for (auto& [p, orig_idx] : queries) {
        auto& [l, r] = p;
        --l; --r;

        while (win_r < r) {
            ++win_r;
            add_win(win_r);
        }
        while (win_l > l) {
            --win_l;
            add_win(win_l);
        }
        while (win_r > r) {
            remove_win(win_r);
            --win_r;
        }
        while (win_l < l) {
            remove_win(win_l);
            ++win_l;
        }

        if (!odd_cnt) {
            ret[orig_idx] = true;
        }
        else {
            ret[orig_idx] = false;
        }
    }

    for (int i = 0; i < q; ++i) {
        if (ret[i]) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
