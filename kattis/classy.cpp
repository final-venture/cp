#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const string DEF = "2222222222222";

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>> order;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        name.pop_back(); // get rid of colon

        string desc;
        cin >> desc;
        int sz = desc.size();
        int cnt = 1;
        for (int i = 0; i < sz; ++i) {
            if (desc[i] == '-') {
                ++cnt;
            }
        }

        int idx = 0;
        int nIdx = cnt - 1;
        string numStr = DEF;
        while (idx < sz) {
            if (desc[idx] == 'u') {
                numStr[nIdx] = '3';
                idx += 6;
            }
            else if (desc[idx] == 'l') {
                numStr[nIdx] = '1';
                idx += 6;
            }
            else if (desc[idx] == 'm') {
                numStr[nIdx] = '2';
                idx += 7;
            }
            --nIdx;
        }

        string garb;
        cin >> garb;

        int num = stoll(numStr);
        order.push_back({-num, name});
    }
    sort(order.begin(), order.end());
    int sz = order.size();
    for (int i = 0; i < sz; ++i) {
        cout << order[i].second << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "==============================" << '\n';
    }
    return 0;
}
