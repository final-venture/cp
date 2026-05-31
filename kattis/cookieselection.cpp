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
    ordered_set<pair<int, int>> os;
    string s;
    int sz = 0;
    while (cin >> s) {
        int cmd = isdigit(s[0]) ? stoi(s) : -1;
        if (cmd == -1) {
            auto toRemove = os.find_by_order(sz / 2);
            cout << toRemove->first << '\n';
            os.erase(toRemove);
            --sz;
        }
        else {
            os.insert({cmd, ++sz});
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
