// Intuitive - https://www.youtube.com/watch?v=c1RL57HvfOs

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

vi arr, even, seg_sum, seg_even, seg_max;

void initialize(ll n)
{
    arr.assign(n, 0);
    even.assign(n, 0);
    seg_sum.assign(4 * n, 0);
    seg_even.assign(4 * n, 0);
    seg_max.assign(4 * n, -inf);
}

// segment tree for sum starts here

void build_sum_segment_tree(ll node , ll left , ll right)
{
    if (left == right)
    {
        seg_sum[node] = arr[left];
        return;
    }

    // calculate mid

    ll mid = (left + right) / 2;

    build_sum_segment_tree(node * 2LL, left, mid);
    build_sum_segment_tree(node * 2LL + 1LL, mid + 1LL, right);

    seg_sum[node] = seg_sum[node * 2LL] + seg_sum[node * 2LL + 1LL];
}

ll get_segment_sum(ll node , ll qlow , ll qhigh , ll left , ll right)
{
    if (qlow > qhigh)
    {
        return 0;
    }

    if (qlow == left and qhigh == right)
    {
        return seg_sum[node];
    }

    ll mid = (left + right) / 2;

    ll ans_left = get_segment_sum(node * 2LL, qlow, min(qhigh, mid), left, mid);
    ll ans_right = get_segment_sum(node * 2LL + 1LL, max(mid + 1LL, qlow), qhigh, mid + 1, right);

    return ans_left + ans_right;
}

void update_segment_sum(ll node, ll pos , ll new_value , ll left , ll right)
{
    if (left == right)
    {
        seg_sum[node] = new_value;
        return;
    }

    ll mid = (left + right) / 2;

    if (pos <= mid)
    {
        update_segment_sum(node * 2LL, pos, new_value, left, mid);
    }
    else
    {
        update_segment_sum(node * 2LL + 1LL, pos, new_value, mid + 1LL, right);
    }

    seg_sum[node] = seg_sum[node * 2LL] + seg_sum[node * 2LL + 1LL];
}

// segment tree for sum ends here

// segment tree for parity = even starts here
void build_even_segment_tree(ll node , ll left , ll right)
{
    if (left == right)
    {
        seg_even[node] = even[left];
        return;
    }

    // calculate mid

    ll mid = (left + right) / 2;

    build_even_segment_tree(node * 2LL, left, mid);
    build_even_segment_tree(node * 2LL + 1LL, mid + 1LL, right);

    seg_even[node] = seg_even[node * 2LL] + seg_even[node * 2LL + 1LL];
}

ll get_segment_even(ll node , ll qlow , ll qhigh , ll left , ll right)
{
    if (qlow > qhigh)
    {
        return 0;
    }

    if (qlow == left and qhigh == right)
    {
        return seg_even[node];
    }

    ll mid = (left + right) / 2;

    ll ans_left = get_segment_even(node * 2LL, qlow, min(qhigh, mid), left, mid);
    ll ans_right = get_segment_even(node * 2LL + 1LL, max(mid + 1LL, qlow), qhigh, mid + 1, right);

    return ans_left + ans_right;
}

void update_segment_even(ll node, ll pos , ll new_value , ll left , ll right)
{
    if (left == right)
    {
        seg_even[node] = new_value;
        return;
    }

    ll mid = (left + right) / 2;

    if (pos <= mid)
    {
        update_segment_even(node * 2LL, pos, new_value, left, mid);
    }
    else
    {
        update_segment_even(node * 2LL + 1LL, pos, new_value, mid + 1LL, right);
    }

    seg_even[node] = seg_even[node * 2LL] + seg_even[node * 2LL + 1LL];
}

// segment tree for parity = even ends here

// segment tree for maximum starts here

void build_max_segment_tree(ll node , ll left , ll right)
{
    if (left == right)
    {
        seg_max[node] = arr[left];
        return;
    }

    // calculate mid

    ll mid = (left + right) / 2;

    build_max_segment_tree(node * 2LL, left, mid);
    build_max_segment_tree(node * 2LL + 1LL, mid + 1LL, right);

    seg_max[node] = max( seg_max[node * 2LL] , seg_max[node * 2LL + 1LL] );
}

ll get_segment_max(ll node , ll qlow , ll qhigh , ll left , ll right)
{
    if (qlow > qhigh)
    {
        return 0;
    }

    if (qlow == left and qhigh == right)
    {
        return seg_max[node];
    }

    ll mid = (left + right) / 2;

    ll ans_left = get_segment_max(node * 2LL, qlow, min(qhigh, mid), left, mid);
    ll ans_right = get_segment_max(node * 2LL + 1LL, max(mid + 1LL, qlow), qhigh, mid + 1, right);

    return  max( ans_left , ans_right );
}

void update_segment_max(ll node, ll pos , ll new_value , ll left , ll right)
{
    if (left == right)
    {
        seg_max[node] = new_value;
        return;
    }

    ll mid = (left + right) / 2;

    if (pos <= mid)
    {
        update_segment_max(node * 2LL, pos, new_value, left, mid);
    }
    else
    {
        update_segment_max(node * 2LL + 1LL, pos, new_value, mid + 1LL, right);
    }

    seg_max[node] = max( seg_max[node * 2LL] , seg_max[node * 2LL + 1LL] );
}

// segment tree for maximum ends here

// main function starts here

signed main()
{
    FIO;

    ll n, q;
    cin >> n >> q;

    //initialize segment trees
    initialize(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)even[i]++;
    }

    // build the sum segment tree
    // build(root vertext,left,right)
    build_sum_segment_tree(1, 0, n - 1);

    // build segment tree for parity = even
    build_even_segment_tree(1, 0, n - 1);

    // build the maximum segment tree
    build_max_segment_tree(1, 0, n - 1);

    while (q--)
    {
        ll type, L, R;
        cin >> type >> L >> R;

        if (type == 1)
        {
            // we need to set A[L] to R;

            L--;

            update_segment_max(1, L, R, 0, n - 1);
            update_segment_even(1, L, R % 2 == 0, 0, n - 1);
            update_segment_sum(1, L, R, 0, n - 1);
        }
        else
        {
            // we need to print the answer for subarray L to R

            L--; R--;

            ll currLength = R - L + 1;
            ll even = get_segment_even(1, L, R, 0, n - 1);
            ll currMax = get_segment_max(1, L, R, 0, n - 1);
            ll currSum = get_segment_sum(1, L, R, 0, n - 1);

            ll cnt = 0;

            if (currMax % 2)
            {
                cnt = even;
            }
            else
            {
                cnt = currLength - even;
            }

            ll ans = ( (currMax * currLength) - currSum - cnt ) / 2;

            ans = ans + cnt;

            cout << ans << endl;
        }
    }

}

// Concise - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/incremental-queries-a7a71194/editorial/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e5 + 14;
struct Node {
    int mx, cnt[2];
    ll sum;
    Node() {
        mx = sum = cnt[0] = cnt[1] = 0;
    }
    Node(int x) {
        sum = mx = x;
        cnt[x % 2] = 1;
        cnt[!(x % 2)] = 0;
    }
    ll ans() {
        return (mx * ll(cnt[0] + cnt[1]) - sum) / 2 + (cnt[!(mx % 2)] + 1) / 2;
    }
    Node operator +(Node o) const {
        o.mx = max(o.mx, mx);
        o.sum = o.sum + sum;
        o.cnt[0] += cnt[0];
        o.cnt[1] += cnt[1];
        return o;
    }
}  seg[maxn * 2];
int n, q;
void upd(int p, int x) {
    for (seg[p += n] = x; p >>= 1; )
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
}
Node get(int l, int r) {
    Node ans;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l % 2)
            ans = seg[l++] + ans;
        if (r % 2)
            ans = ans + seg[--r];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = n; i < 2 * n; i++) {
        int x;
        cin >> x;
        seg[i] = x;
    }
    for (int i = n - 1; i > 0; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if (t == 1)
            upd(l, r);
        else
            cout << get(l, r).ans() << '\n';
    }
}

// I gave up... Undercount because my logic was wrong. I did not take into account the individual elements
// but rather only the 'gap' to be filled / number to be added in total.
// e.g. for [5, 5, 5, 5, 5] to [6, 6, 6, 6, 6], my code would only add 3 operations.
// Stupid mistake...

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

struct xdd
{
    int first;
    int second;
    int cnt;
    int free;
};

vector<int> a;
vector<xdd> seg;
int n, q;

// p1 is lhs, p2 is rhs.
xdd merge(xdd p1, xdd p2)
{
    xdd ret;
    int low, high, elems, free_avail, free_other;
    // we want the number of elements in the lower part
    if (p1.first < p2.first)
    {
        low = p1.first, high = p2.first;
        elems = p1.cnt;
        free_avail = p1.free;
        free_other = p2.free;
    }
    else
    {
        low = p2.first, high = p1.first;
        elems = p2.cnt;
        free_avail = p2.free;
        free_other = p1.free;
    }
    int diff = high - low;

    int free_used = min(free_avail, (diff * elems));
    int eff_diff = diff * elems - free_used;
    int add_ops = free_used + (eff_diff + 1) / 2;
    if (eff_diff & 1) ++free_other; //


    ret.second = p1.second + p2.second + add_ops;
    ret.first = high;
    ret.cnt = p1.cnt + p2.cnt;
    ret.free = free_avail - free_used + free_other;

    return ret;
}

void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {a[l], 0, 1, 0};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
    seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
}

xdd query(int idx, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql) {
        return { -1, -1, -1, -1};
    }
    if (ql <= l && r <= qr) {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    xdd left = query(idx * 2, l, m, ql, qr);
    xdd right = query(idx * 2 + 1, m + 1, r, ql, qr);

    if (left.second == -1) return right;
    if (right.second == -1) return left;
    return merge(left, right);
}

xdd update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx].first = v;
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = l + (r - l) / 2;
    xdd left = update(idx * 2, l, m, t, v);
    xdd right = update(idx * 2 + 1, m + 1, r, t, v);
    return seg[idx] = merge(left, right);
}

void solve()
{
    cin >> n >> q;
    a.resize(n + 1);
    seg.resize(4 * n + 4);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    // for (int i = 1; i <= 7; ++i)
    // {
    //     cout << seg[i].first << ' ' << seg[i].second << '\n';
    // }

    while (q--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            update(1, 1, n, a, b);
            // cout << "AFTER UPDATE" << '\n';
            // for (int i = 1; i <= 7; ++i)
            // {
            //     cout << seg[i].first << ' ' << seg[i].second << '\n';
            // }
        }
        else
        {
            xdd p = query(1, 1, n, a, b);
            cout << p.second << '\n';
        }
    }
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

