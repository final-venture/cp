#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    cin >> N;
    vector<int> cntA(102, 0);
    vector<int> cntB(102, 0);
    for (int i = 1; i <= N; ++i) {
        int A, B;
        cin >> A >> B;
        cntA[A]++;
        cntB[B]++;

        vector<int> cntAA(cntA.begin(), cntA.end());
        vector<int> cntBB(cntB.begin(), cntB.end());
        int curr = 0;
        int l = 0, r = 101;
        int maxx = 0;
        while (curr < i) {
            while (cntAA[l] == 0) {
                ++l;
            }
            while (cntBB[r] == 0) {
                --r;
            }
            maxx = max(maxx, r + l);

            int pairCnt = min(cntBB[r], cntAA[l]);
            curr += pairCnt;
            cntAA[l] -= pairCnt;
            cntBB[r] -= pairCnt;
        }
        cout << maxx << '\n';
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
