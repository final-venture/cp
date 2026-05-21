#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9




// Looking at some values of a[i] - b[i], and what the output is from the samples.
// -2 0 2 ==> 4

// 0 0 ==> 2

// -1 1 ==> 2

// -4 -4 -4 -4 ==> 16

// -1 -1 0 1 -5 3 0 -4 -2 2 ==> 31

// 43739 -28905 299179 ==> 419045

// -1e9 < a_c - b_d < 1e9
// |a_c - b_d| < 1e9

// let's say the current answer is A
// when you swap two elements b_i and b_j, the new answer A' is:
// A' = A + |a_i - b_j| + |a_j - b_i| - |a_i - b_i| - |a_j - b_j|.
// A' - A = delta = |a_i - b_j| + |a_j - b_i| - |a_i - b_i| - |a_j - b_j|.

// We need to maximise |a_i - b_j| + |a_j - b_i| - |a_i - b_i| - |a_j - b_j|.
// WLOG, we can assume a_i < b_i, since |a_i - b_i| = |b_i - a_i|.
// Then, if we visualise them as intervals [a_i, b_i]:
// For some pair:
// Partially overlapping case: no change to total beauty.
// Fully overlapping case: no change to total beauty.
// Separated case: THERE IS A CHANGE. The change is 2 * (a_j - b_i).

// So now, instead of:
// delta = |a_i - b_j| + |a_j - b_i| - |a_i - b_i| - |a_j - b_j|,
// we have a much simpler expression when a_i < b_i, which is the above:
// delta = 2 * (a_j - b_i).

// To maximise this, just find the maximum a_j and minimum b_i possible.
// If the delta is positive, we apply the operation. Otherwise, we don't.




void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        ret += abs(a[i] - b[i]);
    }

    int maxAIdx = -1, minBIdx = -1;
    int maxA = -1, minB = 1e14;
    for (int i = 0; i < n; ++i) {
        if (a[i] > maxA) {
            maxA = a[i];
            maxAIdx = i;
        }
        if (b[i] < minB) {
            minB = b[i];
            minBIdx = i;
        }
    }

    int bestDelta = 2 * (maxA - minB);
    if (bestDelta > 0) {
        ret += bestDelta;
    }

    cout << ret << "\n";
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
