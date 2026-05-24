#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    cin >> n;

    set<pair<int, int>> ret;
    vector<pair<int, int>> piecesHW(n);
    multiset<pair<int, int>> hwOfPieces;
    multiset<pair<int, int>> whOfPieces;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        piecesHW[i] = {a, b};
        hwOfPieces.insert({a, b});
        whOfPieces.insert({b, a});
    }

    int A = 0;
    for (auto [h , w] : piecesHW) {
        A += h * w;
    }

    int cand1_h = 0, cand1_w = 0;
    int cand2_h = 0, cand2_w = 0;
    auto [largestW, _] = *whOfPieces.rbegin();
    auto [largestH, __] = *hwOfPieces.rbegin();

    if (A % largestW == 0) {
        cand1_h = A/largestW; cand1_w = largestW;
    }
    if (A % largestH == 0) {
        cand2_h = largestH; cand2_w = A/largestH;
    }

    while (cand1_h > 0) {
        auto largestWidth = prev(whOfPieces.end());
        auto largestHeight = prev(hwOfPieces.end());
        auto [largestWidthW, largestWidthH] = *largestWidth;
        auto [largestHeightH, largestHeightW] = *largestHeight;
        if (largestWidthW == cand1_w) {
            cand1_h -= largestWidthH;
            whOfPieces.erase(largestWidth);
            hwOfPieces.erase(hwOfPieces.find({largestWidthH, largestWidthW}));
        }
        else if (largestHeightH == cand1_h) {
            cand1_w -= largestHeightW;
            hwOfPieces.erase(largestHeight);
            whOfPieces.erase(whOfPieces.find({largestHeightW, largestHeightH}));
        }
        else {
            break;
        }
        if (whOfPieces.empty()) {
            ret.insert({A/largestW, largestW});
            break;
        }
    }

    hwOfPieces.clear();
    whOfPieces.clear();
    for (auto [a, b] : piecesHW) {
        hwOfPieces.insert({a, b});
        whOfPieces.insert({b, a});
    }

    while (cand2_h > 0) {
        auto largestWidth = prev(whOfPieces.end());
        auto largestHeight = prev(hwOfPieces.end());
        auto [largestWidthW, largestWidthH] = *largestWidth;
        auto [largestHeightH, largestHeightW] = *largestHeight;
        if (largestWidthW == cand2_w) {
            cand2_h -= largestWidthH;
            whOfPieces.erase(largestWidth);
            hwOfPieces.erase(hwOfPieces.find({largestWidthH, largestWidthW}));
        }
        else if (largestHeightH == cand2_h) {
            cand2_w -= largestHeightW;
            hwOfPieces.erase(largestHeight);
            whOfPieces.erase(whOfPieces.find({largestHeightW, largestHeightH}));
        }
        else {
            break;
        }
        if (whOfPieces.empty()) {
            ret.insert({largestH, A/largestH});
            break;
        }
    }

    int retSz = ret.size();
    cout << retSz << '\n';
    for (auto [h, w] : ret) {
        cout << h << ' ' << w << '\n';
    }
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
