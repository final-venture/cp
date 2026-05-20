// O(n * log(n)) Intended solution

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a, b, c;
vector<int> x;
vector<int> dp;
vector<int> pfx;

// reward to transition from state j to state i of dp
int f(int i, int j) {
    int orig = pfx[i] - pfx[j];
    return a * orig * orig + b * orig + c;
}

// for some a < b, returns the index when b overtakes a
int turn(int a, int b) {
    assert(a < b);
    int ret = n + 1;
    // l = b + 1 because b is only used when computing dp states with indices >= b + 1
    // r = n
    // initialise ret = n + 1 because b might never overtake a
    int l = b + 1, r = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int trans_a = dp[a] + f(m, a);
        int trans_b = dp[b] + f(m, b);

        if (trans_b >= trans_a) {
            r = m - 1;
            ret = m;
        }
        else {
            l = m + 1;
        }
    }
    
    return ret;
}

deque<int> dq;

void solve() {
    cin >> n;
    cin >> a >> b >> c;
    x.resize(n + 1);
    pfx.resize(n + 1);
    pfx[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        pfx[i] = pfx[i - 1] + x[i];
    }
    dp.resize(n + 1, -1e18);
    dp[0] = 0;

    dq.push_back(0);

    for (int i = 1; i <= n; ++i) {
        // get rid of invalid elements
        while (dq.size() >= 2 && turn(dq[0], dq[1]) <= i) {
            dq.pop_front();
        }

        // now the front of the dq is o(i)
        int oi = dq.front();
        int cand = dp[oi] + f(i, oi);
        // if (cand > dp[i]) {
            dp[i] = cand;
        // }

        // before pushing i, make sure turning points are monotonically increasing
        while (dq.size() >= 2 && turn(dq[dq.size() - 1], i) <= turn(dq[dq.size() - 2], dq[dq.size() - 1])) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
