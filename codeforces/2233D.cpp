#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// keep track of last index seen for each number.
// when iterating, if we see the number again at index i, and last seen is not i - 1,
//  then we can say i wants to move to mp[a[i]] + 1, or st[a[i]] - 1
// if st[a[i]] 

// impossible if:
// there are 3 items with more than 2 segments
// (now we only have cases with <= 2 items with multiple segments)
// an item has >= 4 segments

// (now we only have cases with <= 2 items which each have <= 3 segments)

// if possible: brute force

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, vector<int>> segStart;
    map<int, vector<int>> segEnd;
    for (int i = 0; i < n;) {
        int currVal = a[i];
        segStart[currVal].push_back(i);
        while (i < n && a[i] == currVal) {
            ++i;
        }
        segEnd[currVal].push_back(i - 1);
    }

    if (segStart.size() == 1) {
        cout << "YES" << '\n';
        return;
    }

    int cnt = 0;
    for (auto& [num, vec] : segStart) {
        if (vec.size() >= 4) {
            cout << "NO" << '\n';
            return;
        }
        else if (vec.size() >= 2) {
            ++cnt;
            if (cnt >= 4) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    if (cnt == 0) {
        cout << "YES" << '\n';
        return;
    }

    auto ok = [n] (int i1, int i2, vector<int>& arr) {
        if (i1 < 0 || i2 < 0 || i1 >= n || i2 >= n) {
            return false;
        }

        swap(arr[i2], arr[i1]);
        unordered_set<int> seen;
        for (int i = 0; i < n;) {
            int currVal = arr[i];
            if (seen.contains(currVal)) {
                swap(arr[i2], arr[i1]);
                return false;
            }
            seen.insert(currVal);
            while (i < n && arr[i] == currVal) {
                ++i;
            }
        }

        swap(arr[i2], arr[i1]);
        return true;
    };

    for (auto& [num, vecS] : segStart) {
        // we can swap segStart to future segStart - 1, or to future segEnd + 1
        // or we can swap segEnd to future segStart - 1 or future segEnd + 1
        auto& vecE = segEnd[num];
        int sz = vecS.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) { // j = i + 1 is perfectly safe here
                
                // All 8 symmetric checks (moving i to j, AND moving j to i)
                bool ret = (
                    ok(vecS[i], vecE[j] + 1, a) || 
                    ok(vecE[i], vecS[j] - 1, a) || 
                    ok(vecS[i], vecS[j] - 1, a) || 
                    ok(vecE[i], vecE[j] + 1, a) || 
                    ok(vecS[j], vecE[i] + 1, a) || 
                    ok(vecE[j], vecS[i] - 1, a) || 
                    ok(vecS[j], vecS[i] - 1, a) || 
                    ok(vecE[j], vecE[i] + 1, a)
                );
                
                if (ret) {
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }

    cout << "NO" << '\n';
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
