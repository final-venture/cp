#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    N *= 2;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    vector<pair<int, int>> sorted(N);
    for (int i = 0; i < N; ++i) {
        sorted[i] = {C[i], i};
    }
    sort(sorted.begin(), sorted.end(), greater<>());

    vector<vector<int>> subarrays;

    int lastProcessed = N;
    for (int i = 0; i < N; ++i) {
        auto [val, idx] = sorted[i];
        if (lastProcessed <= idx) {
            continue;
        }

        int elemsToInsert = lastProcessed - idx;
        if (elemsToInsert > N / 2) {
            cout << -1 << '\n';
            return;
        }

        vector<int> cand(elemsToInsert);
        for (int j = lastProcessed - 1; j >= idx; --j) {
            cand[j - idx] = C[j];
        }
        subarrays.push_back(cand);
        lastProcessed = idx;
    }

    int sz = subarrays.size();
    vector<vector<int>> dp(sz + 1, vector<int>(N / 2 + 1, 0));
    for (int i = 0; i <= sz; ++i) {
        dp[i][0] = 1;
    }

    vector<vector<int>> currSubTaken(sz + 1, vector<int>(N / 2 + 1, -1));
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= N / 2; ++j) {
            dp[i][j] |= dp[i - 1][j];
            int subSz = subarrays[i - 1].size();

            if (j - subSz >= 0 && dp[i - 1][j - subSz] == 1) {
                currSubTaken[i][j] = i - 1;
                dp[i][j] = 1;
            }
        }
    }

    set<int> subs_in_1;
    if (dp[sz][N/2] == 1) {
        int curr_i = sz, curr_j = N/2;
        while (curr_i > 0 && curr_j > 0) {
            int currSzTaken = 0;
            if (currSubTaken[curr_i][curr_j] != -1) {
                currSzTaken = subarrays[currSubTaken[curr_i][curr_j]].size();
            }

            if (currSzTaken > 0) {
                subs_in_1.insert(currSubTaken[curr_i][curr_j]);
            }
            curr_i--;
            curr_j -= currSzTaken;
        }
    }
    else {
        cout << -1 << '\n';
        return;
    }

    vector<int> ret1;
    vector<int> ret2;
    for (int i = sz - 1; i >= 0; --i) {
        int subSz = subarrays[i].size();
        if (subs_in_1.count(i)) {
            for (int j = 0; j < subSz; ++j) {
                ret1.push_back(subarrays[i][j]);
            }
        }
        else {
            for (int j = 0; j < subSz; ++j) {
                ret2.push_back(subarrays[i][j]);
            }
        }
    }

    for (auto x : ret1) {
        cout << x << " ";
    }
    cout << '\n';
    for (auto x : ret2) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
