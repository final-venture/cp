#include <bits/stdc++.h>

using namespace std;

#define int long long
#define EPS 1e-9

// chain xor from 0 to x
int chainXor(int x) {
    if (x <= 0) {
        return 0;
    }

    if (x % 4 == 0) {
        return x;
    }
    else if (x % 4 == 1) {
        return 1;
    }
    else if (x % 4 == 2) {
        return x + 1;
    }
    else {
        return 0;
    }
}

// calculates ceil(x/y)
int intCeil(int x, int y) {
    return (x + y - 1) / y;
}

void solve()
{
    int l, r, i, k;
    cin >> l >> r >> i >> k;
    
    int l2r = chainXor(r) ^ chainXor(l - 1);

    if (r < k) {
        cout << l2r << '\n';
        return;
    }
    
    // for some x = m * 2^i + k:
    int m_min = (l < k) ? 0 : intCeil(l - k, 1LL << i);
    int m_max = (r - k) / (1LL << i);

    if (m_min > m_max) {
        cout << l2r << '\n';
        return;
    }

    int uninterestingCount = m_max - m_min + 1;
    int uninterestingLastI = (uninterestingCount & 1) ? k : 0;
    int uninterestingFirstI = (chainXor(m_max) ^ chainXor(m_min - 1)) << i;

    int ret = l2r ^ uninterestingLastI ^ uninterestingFirstI;
    cout << ret << '\n';
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
