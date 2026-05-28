#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N;
    char B;
    cin >> N >> B;
    unordered_map<char, int> c2vdom {{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 20}, {'T', 10}, {'9', 14}, {'8', 0}, {'7', 0}};
    unordered_map<char, int> c2vndom {{'A', 11}, {'K', 4}, {'Q', 3}, {'J', 2}, {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0}};
    
    int ret = 0;
    for (int i = 0; i < 4 * N; ++i) {
        char card, suit;
        cin >> card >> suit;
        if (suit == B) {
            ret += c2vdom[card];
        }
        else {
            ret += c2vndom[card];
        }
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
