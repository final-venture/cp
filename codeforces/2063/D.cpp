#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define EPS 1e-9
#define int ll

vector<int> b;
vector<int> a;
int n, m;

int step_a(int i)
{
    return (a[n - i - 1] - a[i]);
}

int step_b(int i)
{
    return (b[m - i - 1] - b[i]);
}

bool ok(int i, int j)
{
    return (i >= 0 && j >= 0 && 2 * i + j <= n && 2 * j + i <= m);
}

void solve()
{
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    b.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> ret;
    int sum = 0;
    for (int curra = 0, currb = 0;;)
    {
        if (ok(curra, currb + 1) && ok(curra + 1, currb))
        {
            if (step_a(curra) > step_b(currb))
            {
                sum += step_a(curra);
                ++curra;
            }
            else
            {
                sum += step_b(currb);
                ++currb;
            }
        }
        else if (ok(curra, currb + 1))
        {
            sum += step_b(currb);
            ++currb;
        }
        else if (ok(curra + 1, currb))
        {
            sum += step_a(curra);
            ++curra;
        }
        else if (ok(curra - 1, currb + 2))
        {
            sum -= step_a(curra - 1);
            sum += step_b(currb);
            sum += step_b(currb + 1);
            currb += 2;
            --curra;
        }
        else if (ok(curra + 2, currb - 1))
        {
            sum -= step_b(currb - 1);
            sum += step_a(curra);
            sum += step_a(curra + 1);
            curra += 2;
            --currb;
        }
        else
        {
            break;
        }
        ret.push_back(sum);
    }
    cout << ret.size() << '\n';
    for (int x : ret)
        cout << x << ' ';
    cout << '\n';
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
