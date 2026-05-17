#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct SegTree {
    int n;
    vector<T> seg;
    T IDENTITY_VAL;

    // MODIFY THIS (AND UPDATE FUNCTION IF NECESSARY) TO SWITCH OPERATIONS
    // e.g., return a + b; for sum, or max(a, b); for max
    T combine(T a, T b) {
        return min(a, b); 
    }

    // Constructor: initializes the tree with a size and an identity value
    SegTree(int n, T identity_val) {
        this->n = n;
        this->IDENTITY_VAL = identity_val;
        seg.assign(4 * n, IDENTITY_VAL);
    }

    // Build from an initial array
    void build(const vector<T>& a, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(a, idx * 2 + 1, l, m);
        build(a, idx * 2 + 2, m + 1, r);
        seg[idx] = combine(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    // Point update: set a[pos] = val
    void update(int idx, int l, int r, int pos, T val) {
        if (l == r) {
            seg[idx] = val; // Note: For additions, use seg[idx] += val
            return;
        }
        int m = l + (r - l) / 2;
        if (pos <= m) {
            update(idx * 2 + 1, l, m, pos, val);
        } else {
            update(idx * 2 + 2, m + 1, r, pos, val);
        }
        seg[idx] = combine(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    // Range query: [ql, qr] inclusive
    T query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[idx];
        }
        if (r < ql || l > qr) {
            return IDENTITY_VAL;
        }
        int m = l + (r - l) / 2;
        T left = query(idx * 2 + 1, l, m, ql, qr);
        T right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return combine(left, right);
    }

    // --- Wrapper Functions ---
    void build(const vector<T>& a) { build(a, 0, 0, n - 1); }
    void update(int pos, T val) { update(0, 0, n - 1, pos, val); }
    T query(int ql, int qr) { return query(0, 0, n - 1, ql, qr); }
};
