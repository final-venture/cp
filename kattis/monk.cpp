#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

int a, d;
int totalDist = 0;
vector<pair<int, int>> asc;
vector<pair<int, int>> desc;

bool check(double m) {
    double M = m;
    double ascDist = 0;
    for (int i = 0; i < a; ++i) {
        if (M <= asc[i].second) {
            ascDist += ((M * 1.0) / asc[i].second) * asc[i].first;
            M = 0;
            break;
        }
        else {
            ascDist += asc[i].first;
            M -= asc[i].second;
        }
    }

    M = m;
    double descDist = 0;
    for (int i = 0; i < d; ++i) {
        if (M <= desc[i].second) {
            descDist += ((M * 1.0) / desc[i].second) * desc[i].first;
            M = 0;
            break;
        }
        else {
            descDist += desc[i].first;
            M -= desc[i].second;
        }
    }
    return (ascDist + descDist >= totalDist);
}

void solve()
{
    cin >> a >> d;
    asc.resize(a);
    desc.resize(d);
    for (int i = 0; i < a; ++i) {
        cin >> asc[i].first >> asc[i].second;
        totalDist += asc[i].first;
    }
    for (int i = 0; i < d; ++i) {
        cin >> desc[i].first >> desc[i].second;
    }

    double l = 0, r = 1e8;
    for (int it = 0; it < 100; ++it) {
        double m = l + (r - l) / 2;
        if (check(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << fixed << setprecision(6);
    cout << l << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
