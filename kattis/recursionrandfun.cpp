#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define EPS 1e-9

// a + myRNG() % b + f(i - 1 - (myRNG() % c))
// is equivalent to a + (myRNG() % b) + f(i - (myRNG() % c + 1))

// a = constant
// myRNG() % b is in the range [0, b - 1]

// myRNG() % c is in the range [0, c - 1]
// so - (myRNG() % c + 1) is in the range [-c, -1]
// so i - (myRNG() % c + 1) is in the range [i - c, i - 1]

const int MAXK = 10005;
const int MAXI = 105;
const int OFFSET = 15;

int a, b, c, I, K;
vector<vector<pair<int, int>>> dp;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& vec) {
    sort(vec.begin(), vec.end());
    int n = vec.size();
    if (n <= 1) {
        return vec;
    }

    vector<pair<int, int>> ret{vec[0]};
    for (int i = 1; i < n; ++i) {
        auto& [currLft, currRgt] = ret.back();
        if (currRgt >= vec[i].first) {
            currRgt = max(currRgt, vec[i].second);
        }
        else {
            ret.push_back(vec[i]);
        }
    }
    return ret;
}

void solve() {
    dp.assign(I + OFFSET + 1, vector<pair<int, int>>{});

    for (int i = 0; i <= OFFSET; ++i) {
        dp[i].push_back({1, 1});
    }

    for (int i = OFFSET + 1; i <= OFFSET + I; ++i) {
        for (int j = i - 1 - (c - 1); j <= i - 1; ++j) {
            for (int k = 0; k < dp[j].size(); ++k) {
                auto [oldLB, oldRB] = dp[j][k];
                int newLB = max(1, oldLB + a);
                int newRB = min(MAXK, oldRB + a + b - 1);
                dp[i].push_back({newLB, newRB});
            }
            // we can merge intervals here for optimisation
            dp[i] = mergeIntervals(dp[i]);
        }
    }

    vector<int> reach(MAXK, 0);
    int sz = dp[I + OFFSET].size();
    for (int j = 0; j < sz; ++j) {
        auto [lft, rgt] = dp[I + OFFSET][j];
        // cerr << lft << ' ' << rgt << '\n';
        for (int k = lft; k <= rgt; ++k) {
            reach[k] = 1;
        }
    }

    if (reach[K]) {
        cout << "possible" << '\n';
    }
    else {
        cout << "impossible" << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b >> c >> I >> K)
        solve();
    return 0;
}
