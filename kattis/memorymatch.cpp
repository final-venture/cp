#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    int totalMatchedPairs = 0;
    vector<int> seen(N + 5, 0);
    unordered_map<string, int> scnt;

    for (int i = 0; i < K; ++i) {
        int C1, C2;
        string P1, P2;
        cin >> C1 >> C2;
        cin >> P1 >> P2;
        if (!seen[C1]) {
            scnt[P1]++;
            seen[C1] = 1;
        }
        if (!seen[C2]) {
            scnt[P2]++;
            seen[C2] = 1;
        }
        if (P1 == P2) {
            totalMatchedPairs++;
            seen[C1] = 1;
            scnt[P1] = -1;
        }
    }

    // 2 special cases:
    // if you have only cards of count 1 and count 2 and -1, then you can match all
    // if you have 2 cards that are not seen (count 0), you can match if every other type has count 2 or -1
    // if you have 3+, then it's not possible.

    // 1       2         3       4      5       6       7           8
    // earth    mars    sun      ?     moon    sun     earth        ?
    //                   x                      x

    int ret = 0;
    int ok = 1;
    int thresh = 0;
    int canMatchAll1 = 1;
    int canMatchAll2 = 1;

    if (scnt.size() != N/2) {
        canMatchAll1 = 0;
    }
    if (scnt.size() < N/2 - 1) {
        canMatchAll2 = 0;
    }

    for (auto& [str, cnt] : scnt) {
        if (cnt == 2) {
            ++ret;
        }

        if (cnt == 1) {
            thresh = 10;
            canMatchAll2 = 0;
        }
        if (cnt == 0) {
            canMatchAll1 = 0;
            if (thresh >= 1) {
                ok = 0;
            }
            ++thresh;
        }
    }

    if (canMatchAll1 || canMatchAll2) {
        cout << N/2 - totalMatchedPairs << '\n';
        return;
    }

    cout << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
