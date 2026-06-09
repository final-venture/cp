#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// to get longest sequence, just do regular bracket matching
// remove either l or r

// 8, 10

// test 8: 2 -> 1

// ())(() -> ))((

// test 10: 4 -> 2

// sample: (()())())( -> ()))))(
//          goes 4 -> 1

// mine: (()())())( -> (()().(..(

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // cerr << "k: " << k << '\n';

    vector<int> ret(n, 0);

    // matched[i] == 1 means open bracket, matched[i] == 2 means closed bracket
    for (int it = 0; it < k; ++it) {
        vector<int> matched(n, 1e5);
        int open = 0, closed = 0;
        vector<int> opened;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++open;
                opened.push_back(i);
            }
            else if (s[i] == ')' && closed < open) {
                ++closed;
                matched[i] = opened.size() - 1;
                opened.pop_back();
            }
        }
    
        // if (it == 0) {
        //     cerr << (min(closed, open)) << '\n';
        // }

        int lastClosed = -1;
        int firstOpened = -1;
        int ok = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                if (lastClosed == -1) {
                    lastClosed = i;
                }
                if (matched[i] <= 0) {
                    ok = 1;
                }
            }
            else if (s[i] == '(') {
                firstOpened = i;
            }
        }

        if (ok && firstOpened != -1) {
            s[firstOpened] = '.';
            ret[firstOpened] = 1;
        }
        else if (!ok && lastClosed != -1) {
            s[lastClosed] = '.';
            ret[lastClosed] = 1;
        }
    }
    
    vector<int> matched(n, -1);
    int open = 0, closed = 0;
    vector<int> opened;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++open;
            opened.push_back(i);
        }
        else if (s[i] == ')' && closed < open) {
            ++closed;
            matched[opened.back()] = opened.size() - 1;
            opened.pop_back();
        }
    }
    // cerr << (min(closed, open)) << '\n';

    // int cnt = 0;
    for (auto x : ret) {
        // if (x == 1) {
        //     ++cnt;
        //     assert(cnt <= k);
        // }
        cout << x;
    }
    cout << '\n';

    // cerr << '\n';
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
