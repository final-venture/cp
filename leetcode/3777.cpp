class Solution {
private:
    vector<int> seg;

    void update(int idx, int l, int r, int t, int v) {
        if (l == r && r == t) {
            seg[idx] += v;
            return;
        }
        if (l > t || r < t) {
            return;
        }
        int m = l + (r - l) / 2;
        update(idx * 2 + 1, l, m, t, v);
        update(idx * 2 + 2, m + 1, r, t, v);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[idx];
        }
        if (l > qr || r < ql) {
            return 0;
        }
        int m = l + (r - l) / 2;
        int left = query(idx * 2 + 1, l, m, ql, qr);
        int right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return left + right;
    }
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        seg.resize(4 * n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                update(0, 0, n - 1, i, 1);
            }
        }

        vector<int> ret;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int j = q[1];
                if (j - 1 >= 0) {
                    int toUpdateLeft = (s[j - 1] == s[j]) - (s[j - 1] != s[j]);
                    update(0, 0, n - 1, j, toUpdateLeft);
                }
                if (j + 1 < n) {
                    int toUpdateRight = (s[j] == s[j + 1]) - (s[j] != s[j + 1]);
                    update(0, 0, n - 1, j + 1, toUpdateRight);
                }
                s[j] = (s[j] == 'A') ? 'B' : 'A';
            }
            else if (q[0] == 2) {
                int l = q[1], r = q[2];
                int elemCnt = r - l + 1;
                int notDelete = query(0, 0, n - 1, l + 1, r) + 1;
                ret.push_back(elemCnt - notDelete);
            }
        }
        return ret;
    }
};
