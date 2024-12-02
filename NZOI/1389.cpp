#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

// #define LOCAL

void init()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    stack<int> st; // monotonically decreasing
    st.push(a[0]);
    int unsafe = 1;
    cout << unsafe << '\n';
    unordered_map<int, int> ok;
    for (int x : a)
    {
        ok[x] = 1;
    }
    for (int i = 1; i < n;  ++i)
    {
        while (!st.empty() && st.top() < a[i])
        {
            ok[st.top()] = 1;
            st.pop();
        }
        if (!st.empty() && st.top() == a[i])
        {
            if (ok[a[i]])
            {
                ok[a[i]] = 0;
                --unsafe;
            }
            st.push(a[i]);
            cout << unsafe << '\n';
            continue;
        }
        ++unsafe;
        st.push(a[i]);
        cout << unsafe << '\n';
    }
}

signed main()
{
    init();
#ifdef LOCAL
    int t;
    cin >> t;
    while (t--)
#endif
        solve();
    return 0;
}
