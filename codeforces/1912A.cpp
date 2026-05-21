#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// compute a modified prefix sum for all arrays, where
// pfxS[i][j] represents the sum of a[i][k + 1..j], where k denotes the index of the
//  last positive value to the left of pfxS[i][j].

// compute a modified prefix min, where pfxM[i][j] (again) represents the minimum of a[i][k + 1..j]
//  where k denotes the index of the last positive value to the left of pfxS[i][j].

// We know that for each pfxS[i][j] > 0, if x + pfxM[i][j] >= 0: 
//  then pfxS[i][j] should and can be added to x.

// Since pfxMin is monotonically decreasing:
// Keep curr[i], which represents the last element in the array i that we have considered in x.
//  1. First, iterate through all arrays i, push each pair of {pfxMin[i][nxt], i} into a set
//      (nxt represents the next element such that pfx[i][nxt] > 0, where nxt > lastProcessed[i]).
//  2. Find the maximum pair with the largest pfxM[i][j] in the set. If x + pfxM[i][j] >= 0, then we can add
//      pfxS[i][curr[i]] to x. 
//  3. Every time we add an element to x, pop the pair, and push the next pair of 
//      {pfxMin[i][nxt], i} into the set. Repeat until stuck or elements exhausted.

// current sum is 6
// [-1, -1, -1, -1, -1]
// [-5, 6]

// set: {-1, -5}

void solve()
{
    int x, k;
    cin >> x >> k;
    // a is 0 indexed
    vector<vector<int>> a(k);
    for (int i = 0; i < k; ++i) {
        int sz;
        cin >> sz;
        a[i].resize(sz + 1);
        for (int j = 1; j <= sz; ++j) {
            cin >> a[i][j];
        }
    }

    // MODIFY THIS SO THAT IT RESTARTS AFTER EACH POSITIVE ELEMNT
    vector<vector<int>> pfxS(k);
    for (int i = 0; i < k; ++i) {
        int sz = a[i].size();
        pfxS[i].resize(sz, 0);
        for (int j = 1; j < sz; ++j) {
            if (pfxS[i][j - 1] <= 0) {
                pfxS[i][j] = pfxS[i][j - 1] + a[i][j];
            }
            else {
                pfxS[i][j] = a[i][j];
            }
        }
    }

    // SAME HERE
    vector<vector<int>> pfxM(k);
    for (int i = 0; i < k; ++i) {
        int sz = a[i].size();
        pfxM[i].resize(sz, 0);
        for (int j = 1; j < sz; ++j) {
            if (pfxS[i][j - 1] <= 0) {
                pfxM[i][j] = min(pfxM[i][j - 1], pfxS[i][j]);
            }
            else {
                pfxM[i][j] = pfxS[i][j];
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////
    // // print a
    // for (int i = 0; i < k; ++i) {
    //     int sz = a[i].size();
    //     for (int j = 1; j < sz; ++j) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // // print pfxS
    // for (int i = 0; i < k; ++i) {
    //     int sz = pfxS[i].size();
    //     for (int j = 1; j < sz; ++j) {
    //         cout << pfxS[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // // print pfxM
    // for (int i = 0; i < k; ++i) {
    //     int sz = pfxM[i].size();
    //     for (int j = 1; j < sz; ++j) {
    //         cout << pfxM[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    ////////////////////////////////////////////////////////////////////////////////////

    vector<int> curr(k, 1);
    set<pair<int, int>, greater<>> st;
    for (int i = 0; i < k; ++i) {
        while (curr[i] < a[i].size() && pfxS[i][curr[i]] <= 0) {
            ++curr[i];
        }
        if (curr[i] < a[i].size()) {
            st.insert({pfxM[i][curr[i]], i});
        }
    }

    while (!st.empty()) {
        auto it = st.begin();
        auto [maxMin, currIdx] = *it;
        // MOVED THIS UP FROM THE BOTTOM OF THE LOOP
        // SO THAT NEW INSERTED ELEMENTS CANNOT BE ERASED
        // IF THEY SHARE pfxM[currIdx][curr[currIdx]].
        st.erase(it);
        if (maxMin + x < 0) {
            break;
        }
        
        x += pfxS[currIdx][curr[currIdx]];

        ++curr[currIdx];
        while (curr[currIdx] < a[currIdx].size() && pfxS[currIdx][curr[currIdx]] <= 0) {
            ++curr[currIdx];
        }
        if (curr[currIdx] < a[currIdx].size()) {
            st.insert({pfxM[currIdx][curr[currIdx]], currIdx});
        }
    }

    cout << x << '\n';
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
