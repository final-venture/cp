#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

void solve()
{
    int x;
    cin >> x;
    string numStr = to_string(x);

    int sum_of_digits = 0;
    int first_digit = numStr[0] - '0';

    sort(numStr.begin() + 1, numStr.end());
    // cout << numStr << '\n';

    for (int i = 0; i < numStr.size(); ++i) {
        sum_of_digits += (numStr[i] - '0');
    }

    // cout << sum_of_digits << '\n';
    int turns = 0;
    while (sum_of_digits > 9) {
        if (first_digit - 1 > (numStr.back() - '0')) {
            sum_of_digits -= (first_digit - 1);
            first_digit = 1;
        }
        else {
            sum_of_digits -= (numStr.back() - '0');
            numStr.pop_back();
        }
        ++turns;
        // cout << sum_of_digits << '\n';
    }
    cout << turns << '\n';
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
