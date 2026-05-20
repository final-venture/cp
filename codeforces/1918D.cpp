#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// binary search on the answer
// in each iteration of bs, where we check value c, maintain dp table:
//  dp[i] represents min sum of blocked elements assuming all segments
//      after it have sum <= c.
// If dp[0] <= c, then tighten bounds. Otherwise loosen it.
// First try optimise DP transition with std::set, 
//  if it doesnt work, try monotonic queue.

int n;
vector<int> a;

bool check(int c) {
    vector<int> dp(n + 2);
    dp[n + 1] = 0;

    // smallest element at the front of the queue (left)
    // push elements to the right of the queue, to maintain least recent -> most recent

    // 1. check front of the queue for expired elements
    // 2. before adding elements to the right, repeatedly check back of the queue and 
    //  pop anything that is larger than the one we are about to insert
    deque<int> dq {n + 1};
    int max_j = n + 1;
    int curr_sum = 0;

    for (int i = n; i >= 0; --i) {
        if (a[i] > c) {
            return false;
        }

        while (curr_sum > c) {
            curr_sum -= a[max_j - 1];
            --max_j;
        }

        while (!dq.empty() && dq.front() > max_j) {
            dq.pop_front();
        }
        
        // there is guaranteed to be a value in dq from our first early return
        dp[i] = dp[dq.front()] + a[i];

        while (!dq.empty() && dp[dq.back()] >= dp[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        curr_sum += a[i];
    }
    
    return dp[0] <= c;
}

void solve()
{
    cin >> n;
    a.resize(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = 0;
    a[0] = 0;

    int ret = -1;
    int l = 0, r = 1e15;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (check(m)) {
            r = m - 1;
            ret = m;
        }
        else {
            l = m + 1;
        }
    }
    cout << ret << '\n';
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
