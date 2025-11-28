#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int query(int a, int b)
{
    int res;
    cout << "? " << a << " " << b << endl;
    cin >> res;
    if (res == -1) 
    {
        while (1)
        {
            continue;
        }
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> par(n);
    par[1] = 0;
    queue<int> q;
    q.push(1);
    int curr = 2;
    while (curr < n)
    {
        int r = query(1, curr);
        if (r == 1)
        {
            par[curr] = 0;
            q.push(curr);
            ++curr;
        }
        else
        {
            par[curr] = 1;
            q.pop();
            q.push(curr);
            ++curr;
            break;
        }
    }
    while (curr < n)
    {
        int x = q.front();
        q.pop();
        int r = query(x, curr);
        if (r == 1) continue;
        par[curr] = x;
        q.push(curr);
        ++curr;
    }
    cout << "!";
    for (int i = 1; i < n; ++i)
    {
        cout << ' ' << par[i];
    }
    cout << endl;
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
