#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

#define EPS 1e-9

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 2e6 + 6;
vector<bool> isLucky;

void solve()
{
    ordered_set<int> os;
    isLucky.resize(MAXN, false);
    for (int i = 1; i <= MAXN; ++i) {
        if (i & 1) {
            os.insert(i);
        }
    }

    for (int i = 1; i <= MAXN; ++i) {
        auto it = os.find_by_order(i);
        if (it == os.end()) {
            break;
        }
        int val = *it;
        // we delete [val - 1, 2 * val - 1, 3 * val - 1, ...]
        int lastDeleted = os.size() / val * val - 1;
        for (int j = lastDeleted; j >= val - 1; j -= val) {
            auto toDel = os.find_by_order(j);
            os.erase(toDel);
        } 
    }

    for (auto x : os) {
        isLucky[x] = true;
    }

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n & 1) {
            printf("%d is not the sum of two luckies!\n", n);
            continue;
        }
        auto st = os.upper_bound(n / 2);
        if (st == os.begin()) {
            continue;
        }
        --st;
        bool ok = 0;
        for (auto it = st; ; --it) {
            int val = *it;
            if (n - val <= 0) {
                continue;
            }
            if (isLucky[n - val]) {
                printf("%d is the sum of %d and %d.\n", n, val, n - val);
                ok = 1;
                break;
            }
            if (it == os.begin()) {
                break;
            }
        }
        if (!ok) {
            printf("%d is not the sum of two luckies!\n", n);
        }
    }
}

signed main()
{
    solve();
    return 0;
}
