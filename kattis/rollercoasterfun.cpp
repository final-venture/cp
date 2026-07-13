#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

struct Ride {
    int a;
    int b;
    int t;
};

int N;
vector<Ride> rides;
const int MAXT = 25005;

int f(int i, int k) {
    assert(i >= 0 && i < N);
    int ret = rides[i].a - (k - 1) * (k - 1) * rides[i].b;

    return max(ret, 0LL);
}

void solve() {
    cin >> N;
    rides.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> rides[i].a >> rides[i].b >> rides[i].t;
    }

    vector<int> costB;
    vector<int> weightB;
    vector<int> costUB;
    vector<int> weightUB;
    for (int i = 0; i < N; ++i) {
        if (rides[i].b == 0) {
            costUB.push_back(rides[i].t);
            weightUB.push_back(rides[i].a);
        }
        else {
            for (int j = 1; j < 10000; ++j) {
                int candWeight = f(i, j);
                if (candWeight <= 0) {
                    break;
                }
                costB.push_back(rides[i].t);
                weightB.push_back(candWeight);
            }
        }
    }

    int nB = weightB.size();
    vector<int> dp(MAXT, -1e14);
    dp[0] = 0;
    for (int i = 0; i < nB; ++i) {
        for (int j = MAXT - 1; j >= costB[i]; --j) {
            if (dp[j - costB[i]] <= -1e14) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - costB[i]] + weightB[i]);
        }
    }

    int nUB = weightUB.size();
    for (int i = 0; i < nUB; ++i) {
        for (int j = costUB[i]; j < MAXT; ++j) {
            if (dp[j - costUB[i]] <= -1e14) {
                continue;
            }
            dp[j] = max(dp[j], dp[j - costUB[i]] + weightUB[i]);
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int q;
        cin >> q;
        cout << *max_element(dp.begin(), dp.begin() + q + 1) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
