#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

const int MOD = 998244353;
const int MAXN = 55;

vector<vector<int>> nCr;
vector<int> fact;

void build_nCr() {
    nCr.resize(MAXN, vector<int>(MAXN));
    for (int r = 0; r < MAXN; ++r) {
        nCr[0][r] = 0;
    }
    for (int n = 0; n < MAXN; ++n) {
        nCr[n][0] = 1;
    }
    for (int n = 1; n < MAXN; ++n) {
        for (int r = 1; r < MAXN; ++r) {
            nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % MOD;
        }
    }
}

void build_fact() {
    fact.resize(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> num2cnt;
    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i];
        if (i >= 1) {
            num2cnt[a[i]]++;
        }
    }

    int remaining_zeros = a[0];
    while (true) {
        if (num2cnt.size() <= 1) {
            break;
        }

        auto it1 = num2cnt.begin();
        auto it2 = next(num2cnt.begin());

        auto [num1, cnt1] = *it1;
        auto [num2, cnt2] = *it2;
        int diff = num2 - num1;

        // for (auto [num, cnt] : num2cnt) {
        //     cout << '{' << num << ' ' << cnt << '}' << ", ";
        // }
        // cout << '\n';

        if (remaining_zeros >= diff * cnt1) {
            num2cnt.erase(it1);
            remaining_zeros -= diff * cnt1;
            it2->second += cnt1;
        }
        else if (remaining_zeros >= (diff - 1) * cnt1) {
            num2cnt.erase(it1);
            num2cnt.insert({num1 + (diff - 1), cnt1});
            remaining_zeros -= (diff - 1) * cnt1;
            break;
        }
        else {
            break;
        }
    }

    int fixed_unbal = -1;
    int free_unbal = -1;

    if (num2cnt.size() > 2) {
        cout << 0 << '\n';
        return;
    }
    else if (num2cnt.size() == 2) {
        auto it1 = num2cnt.begin();
        auto it2 = next(num2cnt.begin());
        // cout << it1->first << ' ' << it1->second << '\n';
        // cout << it2->first << ' ' << it2->second << '\n';
        if (it2->first > it1->first + 1) {
            cout << 0 << '\n';
            return;
        }
        fixed_unbal = it2->second;
        free_unbal = remaining_zeros;
    }
    else if (num2cnt.size() == 1) {
        free_unbal = remaining_zeros % n;
        fixed_unbal = 0;
    }
    
    // cout << "unbal cnts" << '\n';
    // cout << fixed_unbal << ' ' << free_unbal << '\n';

    // ways to rearrange the balanced terms
    int term1 = fact[n - (fixed_unbal + free_unbal)];

    // ways to choose the free unbalanced terms
    int term2 = nCr[n - fixed_unbal][free_unbal];

    // ways to choose the total unbalanced terms
    int term3 = fact[free_unbal + fixed_unbal];

    int ret = ((term1 * term2) % MOD) * term3;
    cout << ret % MOD << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    build_nCr();
    build_fact();
    while (t--)
        solve();
    return 0;
}
