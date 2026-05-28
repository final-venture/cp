#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// sequence of machines that he cycles through three times for his workout
// total time = time spent + time recovering

void solve()
{
    vector<int> use(11);
    vector<int> rest(11);

    vector<int> use2(11);
    vector<int> rest2(11);
    vector<int> start2(11);

    for (int i = 1; i <= 10; ++i) {
        cin >> use[i] >> rest[i];
    }
    for (int i = 1; i <= 10; ++i) {
        cin >> use2[i] >> rest2[i] >> start2[i];
    }

    int timer = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 10; ++j) {
            // cout << timer << '\n';
            if (timer > start2[j]) {
                start2[j] += (timer - start2[j]) / (use2[j] + rest2[j]) * (use2[j] + rest2[j]);
            }

            if (timer >= start2[j] + use2[j]) {
                start2[j] += use2[j] + rest2[j];
            }

            if (start2[j] > timer) {
                // the guy is resting or not on the machine
                start2[j] = max(start2[j], timer + use[j]);
                timer = timer + use[j] + rest[j];
            }
            else {
                // the guy is currently on the machine
                timer = start2[j] + use2[j] + use[j] + rest[j];
                start2[j] = max(start2[j] + use2[j] + rest2[j], start2[j] + use2[j] + use[j]);
            }
        }
    }

    cout << timer - rest[10] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
