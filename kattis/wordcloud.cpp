#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int W, N;
int cntMax;
int timer = 1;

inline int getPt(int cnt) {
    int ret = 8 + ceil( 40.0 * (cnt - 4) / (cntMax - 4.0) );
    return ret;
}

void solve()
{
    cntMax = 0;
    vector<pair<string, int> > strCnt;
    for (int i = 0; i < N; ++i) {
        string S;
        int C;
        cin >> S >> C;
        if (C >= 5) {
            strCnt.push_back(make_pair(S, C));
            cntMax = max(cntMax, C);
        }
    }

    int sz = strCnt.size();
    sort(strCnt.begin(), strCnt.end());

    int ret = 0;
    int currW = 0;
    int currS = 0;
    int maxHt = 0;
    for (int i = 0; i < sz; ++i) {
        double t = strCnt[i].first.size();
        int P = getPt(strCnt[i].second);
        int textWidth = ceil(9.0/16 * t * P);
        
        // if our projected width exceeds the limit, put the current text 
        // on the next line and add the answer for this line.
        if (currW + textWidth + currS > W) {
            // cout << maxHt << '\n';
            ret += maxHt;
            currS = 10;
            maxHt = P;
            currW = textWidth;
        }
        else {
            currW += textWidth;
            currS += 10;
            maxHt = max(maxHt, P);
        }
    }
    ret += maxHt;

    cout << "CLOUD " << timer++ << ": " << ret << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> W >> N;
        if (W == 0 && N == 0) {
            break;
        }
        solve();
    }
    return 0;
}
