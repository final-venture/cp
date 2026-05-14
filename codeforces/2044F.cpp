#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

unordered_set<int> A, B;

bool check(int f1, int f2) {
    return (A.find(f1) != A.end() && B.find(f2) != B.end());
}

void solve()
{
    A.clear(); B.clear();
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int aSum = accumulate(a.begin(), a.end(), 0LL);
    int bSum = accumulate(b.begin(), b.end(), 0LL);

    // B' = (aSum - a_i)(bSum - b_j)
    // store possible values of the first term in set A, and the second term in set B
    for (int i = 0; i < n; ++i) {
        A.insert(aSum - a[i]);
    }
    for (int i = 0; i < m; ++i) {
        B.insert(bSum - b[i]);
    }
    
    while (q--) {
        int x;
        cin >> x;
        bool ok = false;
        int absX = abs(x);
        int SQRT = sqrtl(absX);
        for (int i = 1; i <= SQRT; ++i) {
            if (absX % i != 0) {
                continue;
            }
            int f1 = i;
            int f2 = absX / i;
            if (x < 0) {
                if (check(-f1, f2) || check(f1, -f2) || check(-f2, f1) || check(f2, -f1)) {
                    ok = true;
                    break;
                }
            }
            else if (x > 0) {
                if (check(f1, f2) || check(f2, f1) || check(-f1, -f2) || check(-f2, -f1)) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
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
