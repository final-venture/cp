#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define EPS 1e-9

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int N;
    cin >> N;
    // even means we go half -1 and half, odd means we just take the one at the half point.
    ordered_set<pair<int, int>> os;
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        os.insert({x, i});
        if (i & 1) {
            int med = os.find_by_order(i / 2)->first;
            ret += med;
        }
        else {
            int med1 = os.find_by_order(i / 2 - 1)->first;
            int med2 = os.find_by_order(i / 2)->first;
            ret += (med1 + med2) / 2;
        }
    }
    cout << ret << '\n';
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
