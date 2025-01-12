#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define int ll

using namespace std;

int n, k;
vector<int> arr;

string int128_to_string(int x) {
    string s;
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    do {
        s += (char)('0' + x % 10);
        x /= 10;
    } while (x);
    if (neg) {
        s += '-';
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve() {
    cin >> n >> k;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        long long temp;
        cin >> temp;
        arr[i] = temp;
    }
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        intervals[i] = {l, r};
    }
    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        events.push_back({intervals[i].first, i + 1});
        events.push_back({intervals[i].second + 1, -(i + 1)});
    }
    sort(events.begin(), events.end());

    __int128 ret = 0;

    __int128 bestsum = 0;
    set<pair<int, int>> best;
    set<pair<int, int>> nonbest;
    int prev = 0;
    for (auto [time, i] : events) {
        if (time > prev) {
            ret = (ret + bestsum * (time - prev));
        }
        prev = time;
        if (i < 0) {
            auto it = best.find({arr[-i], -i});
            if (it != best.end()) {
                bestsum -= (it->first);
                best.erase({arr[-i], -i});
            } else {
                nonbest.erase({arr[-i], -i});
            }
        } else if (i > 0) {
            nonbest.insert({arr[i], i});
        }
        // try to make best at least k size
        while ((best.size() < k) && (!nonbest.empty())) {
            auto it = nonbest.rbegin();
            bestsum += it->first;
            best.insert({it->first, it->second});
            nonbest.erase(*it);
        }
        // swap elements accordingly
        while (!nonbest.empty() && !best.empty()) {
            auto it1 = nonbest.rbegin();
            auto it2 = best.begin();
            auto [val1, idx1] = *it1;
            auto [val2, idx2] = *it2;
            if (val1 > val2) {
                nonbest.erase(*it1);
                best.erase(it2);
                bestsum -= val2;
                nonbest.insert({val2, idx2});
                best.insert({val1, idx1});
                bestsum += val1;
            } else {
                break;
            }
        }
    }

    cout << int128_to_string(ret % MOD) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}