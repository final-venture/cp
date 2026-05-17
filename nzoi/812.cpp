#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, string> c2s;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        c2s[i] = s;
    }
    map<string, int> s2c;
    for (auto& [c, s] : c2s)
    {
        s2c[s] = c;
    }
    while (q--)
    {
        string cmd, student;
        cin >> cmd >> student;
        if (cmd == "recite")
        {
            cout << c2s[s2c[student]] << '\n';
        }
        else
        {
            string student2;
            cin >> student2;
            swap(s2c[student], s2c[student2]);
        }
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
