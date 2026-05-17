#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int,long long> cnt;
    for (int i = 0; i < 3 * n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int max_val = cnt.rbegin()->first;

    // need_1: number of consecutive sequences started at (x-1), need x next
    // need_2: number of consecutive sequences started at (x-2), need x next
    long long need_1 = 0, need_2 = 0;
    vector<tuple<int,int,int>> result;

    for (int x = 1; x <= max_val + 2; x++) {
        long long c = cnt.count(x) ? cnt[x] : 0;

        if (c < need_1 + need_2) {
            cout << "Impossible\n";
            return 0;
        }

        // Complete sequences that started at x-2
        for (long long i = 0; i < need_2; i++)
            result.emplace_back(x - 2, x - 1, x);

        long long rem = c - need_1 - need_2;
        long long new_seq = rem % 3;
        long long triples = rem / 3;

        for (long long i = 0; i < triples; i++)
            result.emplace_back(x, x, x);

        need_2 = need_1;
        need_1 = new_seq;
    }

    if (need_1 > 0 || need_2 > 0) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Forgiven\n";
    for (auto& [a, b, c] : result)
        cout << a << " " << b << " " << c << "\n";

    return 0;
}