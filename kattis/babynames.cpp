#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;

using namespace std;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define EPS 1e-9

void solve()
{
    ordered_set<string> os_1;
    ordered_set<string> os_2;
    while (true) {
        int type;
        cin >> type;
        if (type == 0) {
            return;
        }
        else if (type == 1) {
            string name;
            int gender;
            cin >> name >> gender;
            if (gender == 1) {
                // male
                os_1.insert(name);
            }
            else if (gender == 2) {
                // female
                os_2.insert(name);
            }
        }
        else if (type == 2) {
            string name;
            cin >> name;
            auto it1 = os_1.find(name);
            auto it2 = os_2.find(name);
            if (it1 != os_1.end()) {
                os_1.erase(it1);
            }
            if (it2 != os_2.end()) {
                os_2.erase(it2);
            }
        }
        else if (type == 3) {
            string a, b;
            int gender;
            cin >> a >> b >> gender;
            int ret = 0;
            if (gender == 0 || gender == 1) {
                ret += os_1.order_of_key(b) - os_1.order_of_key(a);
            }
            if (gender == 0 || gender == 2) {
                ret += os_2.order_of_key(b) - os_2.order_of_key(a);
            }
            cout << ret << '\n';
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
