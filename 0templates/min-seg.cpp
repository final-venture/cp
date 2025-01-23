vector<int> seg;

void update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = v;
        return;
    }
    if (l > t || r < t)
    {
        return;
    }
    int m = l + (r - l) / 2;
    update(idx * 2 + 1, l, m, t, v);
    update(idx * 2 + 2, m + 1, r, t, v);
    seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

int query(int idx, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return seg[idx];
    }
    if (r < ql || l > qr)
    {
        return INT_MAX;
    }
    int m = l + (r - l) / 2;
    int left = query(idx * 2 + 1, l, m, ql, qr);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr);
    return min(left, right);
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = ? ;
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}
