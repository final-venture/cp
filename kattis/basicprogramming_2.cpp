#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int N, t;
    cin >> N >> t;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    if (t == 1) {
        unordered_set<int> As;
        for (auto x : A) {
            As.insert(x);
        }

        for (auto x : A) {
            if (As.contains(7777 - x) && 7777 - x != x) {
                cout << "Yes";
                return;
            }
        }

        cout << "No";
    }
    else if (t == 2) {
        unordered_set<int> As;

        for (auto x : A) {
            if (As.contains(x)) {
                cout << "Contains duplicate";
                return;
            }
            As.insert(x);
        }

        cout << "Unique";
    }
    else if (t == 3) {
        unordered_map<int, int> Am;
        for (auto x : A) {
            Am[x]++;
            if (Am[x] > N/2) {
                cout << x;
                return;
            }
        }

        cout << -1;
    }
    else if (t == 4) {
        sort(A.begin(), A.end());
        if (N & 1) {
            cout << A[N / 2];
        }
        else {
            cout << A[N / 2 - 1] << ' ' << A[N / 2];
        }
    }
    else if (t == 5) {
        sort(A.begin(), A.end());
        for (int i = 0; i < N; ++i) {
            if (A[i] >= 100 && A[i] <= 999) {
                cout << A[i] << ' ';
            }
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
