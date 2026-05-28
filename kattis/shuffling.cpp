#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int n;
    string type;
    cin >> n >> type;
    vector<int> card(n);
    iota(card.begin(), card.end(), 0LL);
    vector<int> currCard(card.begin(), card.end());

    int ret = 0;
    // int its = 0;
    while (true) {
        vector<int> newCard;
        if (type == "in") {
            int l = 0, r = n / 2;
            while (r < n) {
                newCard.push_back(currCard[r]);
                ++r;
                if (l < n / 2) {
                    newCard.push_back(currCard[l]);
                    ++l;
                }
            }
        }
        else if (type == "out") {
            int l = 0, r = (n + 1) / 2;
            while (l < (n + 1) / 2) {
                newCard.push_back(currCard[l]);
                ++l;
                if (r < n) {
                    newCard.push_back(currCard[r]);
                    ++r;
                }
            }
        }
        currCard = newCard;
        ++ret;
        // for (auto x : newCard) { 
        //     cout << x << ' ';
        // }
        // cout << '\n';
        // for (auto x : card) {
        //     cout << x << ' ';
        // }
        // cout << "\n\n";
        if (newCard == card) {
            cout << ret << '\n';
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
