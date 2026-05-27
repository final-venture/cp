#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 100000;

int N;
int orig[MAXN + 5];
int seg[4 * (MAXN + 5)];

int query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2, l, m, ql, qr);
    int right = query(idx * 2 + 1, m + 1, r, ql, qr);

    return left + right;
}

void update(int idx, int l, int r, int t, int v) {
    if (l > t || r < t) {
        return;
    }
    if (l == r && r == t) {
        seg[idx] = v;
        return;
    }
    int m = l + (r - l) / 2;
    update(idx * 2, l, m, t, v);
    update(idx * 2 + 1, m + 1, r, t, v);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

signed main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        orig[x] = i;
    }

    // initialise segtree to 1, representing unsorted.
    for (int i = 1; i < MAXN + 3; ++i) {
        update(1, 1, N, i, 1);
    }

    int l = 1, r = N;
    while (l <= r) {
        // process l
        int swapsL = query(1, 1, N, 1, orig[l] - 1);
        cout << swapsL << '\n';
        update(1, 1, N, orig[l], 0);
        ++l;

        // check if we need to break early
        if (l > r) {
            break;
        }

        // process r
        int swapsR = query(1, 1, N, orig[r] + 1, N);
        cout << swapsR << '\n';
        update(1, 1, N, orig[r], 0);
        --r;
    }
}
