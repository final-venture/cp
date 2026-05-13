#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void insert(int x) {
    cout << "I " << x << endl;
}

void query(int y) {
    cout << "Q " << y << endl;
}

// check if we need to increase value of left pointer
bool check(int m, int prev_cnt) {
    int curr_cnt;
    query(m);
    cin >> curr_cnt;
    if (curr_cnt > prev_cnt) {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    int n;
    cin >> n;
    int card;

    cout << 0 << endl;
    insert(0);
    cin >> card;
    if (card == 1) {
        // k = 1
        // S = {0}

        insert((1LL << n) - 1);
        cin >> card;

        // S = {0, c}
        int c = 0;
        int l = 1, r = (1LL << n) - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m, 0)) {
                c = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        cout << "A 1 " << c << endl;
    }
    else {
        // k = 2 or k = 3
        // S = {0, c}
        
        int c = 0;
        int l = 1, r = (1LL << n) - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m, 0)) {
                c = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        if (c == (1LL << n) - 1) {
            insert(1);
            int new_card;
            cin >> new_card;
            if (new_card == card) {
                // k = 2
                cout << "A 2 " << c << endl;
            }
            else {
                // k = 3
                cout << "A 3 " << c << endl;
            }
        } 
        else {
            insert((1LL << n) - 1);
            cin >> card;

            int k_is_2 = 0;
            query((1LL << n) - 1);
            cin >> k_is_2;
            if (k_is_2 > 0) {
                // k = 2
                cout << "A 2 " << c << endl;
            }
            else {
                // k = 3
                cout << "A 3 " << c << endl;
            }
        }
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
